import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
	String k[][] = new String[10000][2];
		int lowtemp = 201;
		String lowcity = "";
		Scanner input = new Scanner(System.in);
		for (int i = 0; i<10001; i++) {
			k[i][0] = input.next();
			k[i][1] = input.next();

			if (Integer.parseInt(k[i][1]) < lowtemp) {
				lowtemp = Integer.parseInt(k[i][1]);
				lowcity = k[i][0];
			}
			if (k[i][0].equals("Waterloo")) {
				break;
			}
		}
		System.out.println(lowcity);
    }
}