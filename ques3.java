
package toc;

import java.io.*;
import java.util.*;

public class TOC {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args)throws IOException{
       
        Scanner reader=new Scanner(System.in);
        int optionSel;             
        char input;              
        int Operate;              
        int state=0;                     
                     
        int flag=0;     
        do
        {
        System.out.print("Enter input (D:Dime(10$)||N:Nickel(5$)||R:Reset):");
        
        input= reader.next().charAt(0);
        
            switch (input) {
                case 'N':
                    state=(state+1)%4;
                    break;
                case 'D':
                    state=(state+2)%4;
                    break;
                case 'R':
                    state=0;
                    break;
                default:
                    flag=1;
                    break;
            }
        if(flag==1)
        {    flag=0;            
            continue;
        }
        
        if(state==3)
        {
            Operate=1;
        }
        
        else
        {
            Operate=0;
        }
        
        System.out.print("State in Machine=");
        System.out.println(state);
        
        if(Operate==0)
            System.out.println("Closed");
        else
            System.out.println("IN operation. Take your order");
        
        System.out.println("input more amount?(Yes=1; No=0)");
        optionSel=reader.nextInt();
  
        if(optionSel==0)
            break;
        } while(true);
        
    }
    
}
