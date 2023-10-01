import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.time.Instant;
import java.util.Base64;
import java.security.SecureRandom;
import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;

public class OTPGenerator {
    private static final String HMAC_ALGORITHM = "HmacSHA1";
    private static final int DIGITS = 6;
    private static final long TIME_STEP_SECONDS = 30;
    private static final byte[] SECRET_KEY;
    private static final int OTP_VALIDITY_SECONDS = 300; // 5*60 seconds

    private static boolean isOTPVerified = false;

    static {
        int keyLengthBytes = 32;
        SECRET_KEY = generateRandomKey(keyLengthBytes);
    }

    public static void main(String[] args) {
        int maxAttempts = 3;
        long otpStartTime = Instant.now().getEpochSecond();
        Scanner scanner = new Scanner(System.in);

        // Set up a timer to terminate the program after OTP_VALIDITY_SECONDS
        Timer timer = new Timer();
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                if (!isOTPVerified) {
                    System.out.println("\nOTP expired. Program terminated.");
                    System.exit(0);
                }
            }
        }, OTP_VALIDITY_SECONDS * 1000);

        System.out.println("\nOTP is valid for 5 minutes.");
        for (int attempts = 1; attempts <= maxAttempts; attempts++) {
            long counter = getCurrentCounter();

            String otp = generateOTP(SECRET_KEY, counter, DIGITS);
            System.out.println("\nGenerated OTP: " + otp);

            System.out.print("\nEnter OTP: ");
            String userEnteredOTP = scanner.nextLine();

            boolean isValid = verifyOTP(userEnteredOTP, otpStartTime);
            if (isValid) {
                isOTPVerified = true;
                System.out.println("\nOTP is valid, Access Granted\n");
                break;
            } else {
                System.out.println("\nOTP is invalid.");
                if (attempts < maxAttempts) {
                    System.out.println("\nYou have " + (maxAttempts - attempts) + " attempts remaining.");
                } else {
                    System.out.println("\nMaximum attempts reached, Try Again.");
                    break;
                }
            }
        }
        
        timer.cancel(); // Cancel the timer since OTP is verified
        scanner.close();
    }

    private static byte[] generateRandomKey(int length) {
        SecureRandom secureRandom = new SecureRandom();
        byte[] key = new byte[length];
        secureRandom.nextBytes(key);
        return key;
    }

    private static long getCurrentCounter() {
        return Instant.now().getEpochSecond() / TIME_STEP_SECONDS;
    }

    private static String generateOTP(byte[] secretKey, long counter, int digits) {
        try {
            byte[] counterBytes = new byte[8];

            for (int i = 7; i >= 0; i--) {
                counterBytes[i] = (byte) counter;
                counter >>= 8;
            }

            SecretKeySpec keySpec = new SecretKeySpec(secretKey, HMAC_ALGORITHM);
            Mac mac = Mac.getInstance(HMAC_ALGORITHM);
            mac.init(keySpec);

            byte[] hash = mac.doFinal(counterBytes);

            int offset = hash[hash.length - 1] & 0xF;
            int binary =
                ((hash[offset] & 0x7F) << 24) |
                ((hash[offset + 1] & 0xFF) << 16) |
                ((hash[offset + 2] & 0xFF) << 8) |
                (hash[offset + 3] & 0xFF);

            int otp = binary % (int) Math.pow(10, digits);
            return String.format("%0" + digits + "d", otp);
        } catch (NoSuchAlgorithmException | InvalidKeyException e) {
            e.printStackTrace();
            return null;
        }
    }

    private static boolean verifyOTP(String userEnteredOTP, long startTime) {
        long currentTime = Instant.now().getEpochSecond();
        String generatedOTP = generateOTP(SECRET_KEY, startTime / TIME_STEP_SECONDS, DIGITS);
        return currentTime - startTime <= OTP_VALIDITY_SECONDS && userEnteredOTP.equals(generatedOTP);
    }
}
