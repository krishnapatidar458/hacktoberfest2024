import java.util.*;
public class OddOrEven{
    public static void main(String arg[]){
        Scanner sc=new Scanner(System.in);
        int number=sc.nextInt();
        
        if(number%2==0)
            System.out.println("Number is even");
        else
            System.out.println("Number is odd");
    }
}
