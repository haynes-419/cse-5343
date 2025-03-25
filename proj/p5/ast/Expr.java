package ast;
import java.io.PrintStream;

public abstract class Expr extends ASTNode {
    public int type;
    public String value = "";
    public String tempVar = "";
    public abstract void print(PrintStream ps);
    public abstract void check();
    public abstract void genCode();
}
