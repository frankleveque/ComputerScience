package testing;
import datastructures.Stack;
import java.util.*;

/** 
 * Implements a stack data structure from a double linked list, 
 * adds top, pop, and push operations
 * @author Frank Leveque
 * @creator Frank Leveque
 */
public class StackTest{

    public static void main(String[] args){
        boolean isRunning = true;
        Stack dlist = new Stack();
        Scanner scan = new Scanner(System.in);
        Random rnd = new Random();

        while(isRunning){
            System.out.println("\nStack Test Menu");
            System.out.println("===============");
            System.out.println("1) Push");
            System.out.println("2) Pop");
            System.out.println("3) Top");
            System.out.println("4) Print Forwards");
            System.out.println("5) Print Backwards");
            System.out.println("6) Exit");
            System.out.print("Option: ");

            String temp = scan.next();
            switch(temp){
            case "1": 
                int rndNum = rnd.nextInt(10);
                dlist.push(rndNum); 
                System.out.println("Pushed " + rndNum + " to stack"); break;
            case "2": 
                Object popped = dlist.pop();
                if(popped == null){
                    System.out.println("Empty List - Cannot pop()"); break; 
                } else{
                    System.out.println(popped);  
                } break;
            case "3": 
                Object top = dlist.top();
                if(top == null){
                    System.out.println("Empty List - Cannot top()"); break; 
                } else{
                    System.out.println(top); 
                } break; 
            case "4": 
                dlist.printForwards(); break;            
            case "5": 
                dlist.printBackwards(); break;         
            case "6": 
                isRunning=false; 
                System.out.println("Exiting..."); break;         
            default: 
                System.out.println("Invalid Choice - Ignoring");
            }
        }
        scan.close();
    }
}
