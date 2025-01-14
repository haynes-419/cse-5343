package ast;
import java.io.PrintStream;

public class BinaryExpr extends Expr {
    public static final int PLUS = 1;
    public static final int MUL = 2;
    public static final int ASSIGN = 3;
    public final Expr expr1, expr2;
    public final int op;
    public BinaryExpr(Expr e1, int oper, Expr e2) {
	expr1 = e1; 
	expr2 = e2;
	op = oper;
    }
    public void print(PrintStream ps) {
	ps.print("(");
	expr1.print(ps);
	switch (op) {
	case PLUS: ps.print("+"); break;
	case MUL: ps.print("*"); break;
	case ASSIGN: ps.print("="); break;
	}
	expr2.print(ps);
	ps.print(")");
    }
}
