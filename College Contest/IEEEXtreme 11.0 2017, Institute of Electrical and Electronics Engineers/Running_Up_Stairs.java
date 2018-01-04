import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

class Running_Up_Stairs{
	public static BigInteger[] f = new BigInteger[25000];
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		f[0] = BigInteger.valueOf(1);
		f[1] = BigInteger.valueOf(1);
		f[2] = BigInteger.valueOf(2);
		for (int i = 3; i <= 22000; ++i){
			f[i] = f[i-1].add(f[i-2]);
		}
		int T;
		T = in.nextInt();
		for (int i = 0; i < T; ++i){
			int tmp;
			tmp = in.nextInt();
			System.out.println(f[tmp]);
		}
	}
}