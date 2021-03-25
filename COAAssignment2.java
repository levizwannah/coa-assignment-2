/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package coaassignment2;

import java.util.Scanner;
/**
 *
 * @author mkino
 */
public class COAAssignment2 {

    
    public static void main(String[] args) {
        double num,fracPart= 0,number;
        int intPart=0,m;
        StringBuilder k=new StringBuilder();
        Scanner scan=new Scanner(System.in);
        System.out.println("Number inputted:");
        num=scan.nextDouble();
        System.out.println("No. upto which precision comes into effect:");
        m=scan.nextInt();
        System.out.print("Binary output is:");
        int n = (int)num;
        fracPart=num-n;
        while(m!=0)
        {
          intPart=(int) (fracPart*2);
          k.append(intPart);
          number=fracPart*2;
          fracPart=number-intPart;
          m--;
        }
        
        System.out.println(k);
    }
    
}
