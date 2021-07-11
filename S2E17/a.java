package S2E17;

import java.util.Scanner;

public class a {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String str = in.nextLine();
        // remove the last character of str
        str = str.substring(0, str.length() - 1);
        String[] words = str.split(" ");
        String lastword = words[words.length - 1];
        Character lastCharacter = lastword.charAt(lastword.length() - 1);
        Character[] filter = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
        // for (String word : words)
        // {
        //     System.out.println(word);
        // }
        for (Character c : filter) {
            if (c == lastCharacter) {
                System.out.println("YES");
                in.close();
                return;
            }
        }
        System.out.println("NO");
        in.close();
    }
}
