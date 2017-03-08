import java.util.ArrayList;
import java.util.List;

import static java.lang.System.out;

/**
 * Zadanie dotyczy kopalni "Moria".
 * 
 * Kopalnia rozpoczyna się centralnym szybem, na głębokości lv=1.
 * Z każdej komory wychodzą potencjalnie dwie drogi w dół.
 * 
 * Kod poniżej tworzy kopalnię, rysuje jej mapę. 
 * 
 * Zadanie: spowodować, by drogi w dół pojawiały się tylko w pewnych przypadkach (np. z prawdopodobieństwem 0.99).
 * Narysować taką niesymetryczną kopalnię.
 * Znaleźć najniższy poziom do którego można dość.
 * 
 * (No i: przepisać całość na C++; używać vector<int> zamiast List<Integer> )
 */


public class MinesOfMoria {
    List<Integer>[] chs;
    int rooms;

    void printRoom(int rt, int lv, boolean[][] screen, int x, int len) {
        screen[lv][x] = true;
        int child_x = x - len;
        for(int c : chs[rt]) {
            printRoom(c, lv+1, screen, child_x, len/2);
            child_x += 2 * len;
        }
    }

    void printTheMine() {
        boolean[][] screen = new boolean[20][150];
        printRoom(1, 1, screen, 75, 32);
        for (int i = 0; i < screen.length; i++) {
            for (int j = 0; j < screen[0].length; j++) {
                out.print(screen[i][j] ? 'o' : '.');
            }
            System.out.println();
        }
    }

    void createGraph(int rt, int lv) {
        chs[rt] = new ArrayList<>();
        System.out.println("creating room " + rt + " at depth " + lv);
        if (lv<7) {
            for (int i = 0; i < 2; i++) {
                int id = (++rooms);
                chs[rt].add(id);
                createGraph(id, lv+1);
            }
        }
        System.out.println("finished room " + rt + " at depth " + lv + "; ways visible to:" + chs[rt]);
    }

    public MinesOfMoria() {
        chs = new List[1000];
        rooms = 1;
        createGraph(1, 1);
    }

    public static void main(String[] args) {
        MinesOfMoria moria = new MinesOfMoria();
        moria.printTheMine();
    }

}
