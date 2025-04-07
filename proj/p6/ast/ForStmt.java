package ast;
import java.io.PrintStream;

public class ForStmt extends Stmt {
    public final Expr expr1;
    public final Expr expr2;
    public final Expr expr3;
    public final Stmt stmt;

    public ForStmt(Expr e1, Expr e2, Expr e3, Stmt s){
        expr1 = e1;
        expr2 = e2;
        expr3 = e3;
        stmt = s;
    }

    public void print(PrintStream ps, String space){
        ps.print(space + "for (");
        expr1.print(ps);
        ps.print("; ");
        expr2.print(ps);
        ps.print("; ");
        expr3.print(ps);
        ps.println(")");

        stmt.print(ps, space + " ");
    }
}