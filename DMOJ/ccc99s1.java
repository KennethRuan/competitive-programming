import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		List<String> cards = new LinkedList<String>();
		String[] deck = new String[53];
		List<String> high_cards = new ArrayList<String>();
		high_cards.add("ace");
		high_cards.add("king");
		high_cards.add("queen");
		high_cards.add("jack");
		int a_points = 0;
		int b_points = 0;
		
		for(int x = 0; x<52;x++)
			cards.add(sc.nextLine());
//		cards.add(" ");
		deck = cards.toArray(new String[cards.size()]);
		
		for(int x = 0; x<52;x++) {
			if(deck[x].equals("ace") && deck.length-x > 4) {
				if(Collections.disjoint(cards.subList(x+1, x+5), high_cards)) {
					if(x%2==0) {
						System.out.println("Player A scores 4 point(s).");
						a_points += 4;
					}
					if(x%2==1) {
						System.out.println("Player B scores 4 point(s).");
						b_points += 4;
					}
				}
			}
			if(deck[x].equals("king") && deck.length-x > 3) {

				if(Collections.disjoint(cards.subList(x+1, x+4), high_cards)) {
					if(x%2==0) {
						System.out.println("Player A scores 3 point(s).");
						a_points += 3;
					}
					if(x%2==1) {
						System.out.println("Player B scores 3 point(s).");
						b_points += 3;
					}
				}
			}
			if(deck[x].equals("queen") && deck.length-x > 2) {
				if(Collections.disjoint(cards.subList(x+1, x+3), high_cards)) {
					if(x%2==0) {
						System.out.println("Player A scores 2 point(s).");
						a_points += 2;
					}
					if(x%2==1) {
						System.out.println("Player B scores 2 point(s).");
						b_points += 2;
					}
				}
			}
			if(deck[x].equals("jack") && deck.length-x > 1) {
				if(Collections.disjoint(cards.subList(x+1, x+2), high_cards)) {
					if(x%2==0) {
						System.out.println("Player A scores 1 point(s).");
						a_points += 1;
					}
					if(x%2==1) {
						System.out.println("Player B scores 1 point(s).");
						b_points += 1;
					}
				}
			}
		}
		System.out.printf("Player A: %d point(s).\n", a_points);
		System.out.printf("Player B: %d point(s).", b_points);
	}
}