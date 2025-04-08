package ast;
import java.io.PrintStream;

public class Label extends Stmt {
    public final String id; 
    public Label(String i) {
        id = i;
    }

    public void print(PrintStream ps, String space) {
        ps.println(space + id + " :");
    }
}
