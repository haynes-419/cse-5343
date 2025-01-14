package ast;
import java.io.PrintStream;

public class BinaryExpr extends Expr {
    public static final int PLUS = 1;
    public static final int MUL = 2;
    public static final int ASSIGN = 3;
	public static final int SUB = 4;
	public static final int DIVIDE = 5;
	public static final int MODULO = 6;
    public static final int PLUSASSIGN = 7;
    public static final int MULASSIGN = 8;
	public static final int SUBASSIGN = 9;
	public static final int DIVIDEASSIGN = 10;
	public static final int MODULOASSIGN = 11;
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
	case SUB: ps.print("-"); break;
	case MUL: ps.print("*"); break;
	case DIVIDE: ps.print("/"); break;
	case MODULO: ps.print("%"); break;
	case ASSIGN: ps.print("="); break;
	case PLUSASSIGN: ps.print("+="); break;
	case SUBASSIGN: ps.print("-="); break;
	case MULASSIGN: ps.print("*="); break;
	case DIVIDEASSIGN: ps.print("/="); break;
	case MODULOASSIGN: ps.print("%="); break;
	}
	expr2.print(ps);
	ps.print(")");
    }
}
