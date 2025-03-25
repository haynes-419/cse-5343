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

    @Override
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

    @Override
    public void check() {
        expr1.check();
        expr2.check();
        expr3.check();
        stmt.check();
    }

    @Override
    public void genCode(){
        System.out.print("for (");
        expr1.genCode();
        System.out.print("; ");
        expr2.genCode();
        System.out.print("; ");
        expr3.genCode();
        System.out.println(")");

        stmt.genCode();
    }
}