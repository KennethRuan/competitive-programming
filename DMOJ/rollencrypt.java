import java.io.*;
import java.util.*;
public class rollencrypt {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int k = Integer.parseInt(r.readLine());
		String inp = r.readLine();
		char[] str = inp.toCharArray();
//		List<Character> nstr = new ArrayList<Character>();
		char[] nstr = new char[str.length];
		for (int i = 0; i < k; i++)
			nstr[i] = (str[i]);
		char out;
		for(int i = k; i < str.length;i++) {
			int a = most_common(Arrays.copyOfRange(str,i-k, i));//0-25
			if ((a + (((int)(str[i]))-96)) % 26 == 0)
				a = 26;
			else
				a = (a + (((int)(str[i]))-96))%26;
			a += 96;
			out = (char)a;
			nstr[i] = out;
//			for (int j = 0; j < a.length; j++)
//				System.out.print(a[j]);
//			System.out.println();
		}
		System.out.println(String.valueOf(nstr));
	}

	
	public static int most_common(char[] lst) {
		int[] count = new int[27];
		String s = new String(lst);
		for (int i = 0; i < lst.length; i++) {
			count[s.charAt(i)-96]++;
		}
		int max = 0;
		int elm = 0;
		for (int i = 0; i < 27; i++) {
			if (count[i] > max) {
				max = count[i];
				elm = i;
			}
		}
		return elm;
		
	}
}