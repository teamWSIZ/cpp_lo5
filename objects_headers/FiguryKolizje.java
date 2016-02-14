package WW;

import java.awt.*;

/**
 * Created by pm on 1/20/16.
 */

class Figura {
    Color c;  //jakieś wspólne funkcje i własności
}

class K extends Figura {
    int x = 0;
}

class P extends Figura {
    int y = 0;
}

class Zderzacz {
    static boolean czyKolizja(Figura f1, Figura f2) {
        if (f1 instanceof K) {
            if (f2 instanceof K) return ((K) f1).x == ((K) f2).x;
            if (f2 instanceof P) return ((K) f1).x == ((P) f2).y;
        }
        if (f1 instanceof P) {
            if (f2 instanceof P) return ((P) f1).y == ((P) f2).y;
            if (f2 instanceof K) return czyKolizja(f2, f1);
        }
        throw new RuntimeException("Takiej kolizji nie potrafię policzyć");
    }
}



public class FiguryKolizje {
    public static void main(String[] args) {
        K k = new K();
        k.x = 11;
        P p = new P();
        p.y = 11;
        System.out.println(Zderzacz.czyKolizja(k, p));
    }
}
