import java.util.*;
class reverse_word {
    public String reverseWords(String s) {
        // Split the input string into words using whitespace as the delimiter
        String[] words = s.split(" ");

        // Initialize a StringBuilder to build the reversed sentence
        StringBuilder reversed = new StringBuilder();

        // Iterate through the words, reverse each word, and append it to the result
        for (String word : words) {
            StringBuilder reversedWord = new StringBuilder(word);
            reversedWord.reverse();
            reversed.append(reversedWord).append(" ");
        }

        // Remove the trailing space and return the reversed sentence
        return reversed.toString().trim();
    }
    public static void main(String[] args) {
        reverse_word reverse_word  = new reverse_word();
    
        String s1 = "Let's take LeetCode contest";
        String result1 = reverse_word.reverseWords(s1);
        System.out.println(result1);  // Output: "s'teL ekat edoCteeL tsetnoc"
    
        String s2 = "God Ding";
        String result2 = reverse_word.reverseWords(s2);
        System.out.println(result2);  // Output: "doG gniD"
    }
}
