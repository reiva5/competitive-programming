import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class inversefactorial{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		BigInteger res = in.nextBigInteger();
		int cnt = 1;
		for (; res.compareTo(BigInteger.valueOf(1)) != 0; ++cnt){
			res = res.divide(BigInteger.valueOf(cnt));
		}
		System.out.println(cnt-1);
	}
}