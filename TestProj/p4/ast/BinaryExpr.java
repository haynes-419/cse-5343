package ast;

import java.io.PrintStream;
import java.util.Arrays;
import java.util.List;

import compiler.Compiler;

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
    public static final int LESSTHEN = 12;
    public static final int LESSTHENEQUAL = 13;
    public static final int GREATERTHEN = 14;
    public static final int GREATERTHENEQUAL = 15;
    public static final int EQUALEQUAL = 16;
    public static final int NOTEQUAL = 17;
    public final Expr expr1, expr2;
    public final int op;
    public String tempVarName = "";

    public BinaryExpr(Expr e1, int oper, Expr e2) {
        expr1 = e1;
        expr2 = e2;
        op = oper;
		type = 3;
    }

    @Override
    public void print(PrintStream ps) {
        ps.print("(");
        expr1.print(ps);
        switch (op) {
            case PLUS:
                ps.print("+");
                break;
            case SUB:
                ps.print("-");
                break;
            case MUL:
                ps.print("*");
                break;
            case DIVIDE:
                ps.print("/");
                break;
            case MODULO:
                ps.print("%");
                break;
            case ASSIGN:
                ps.print("=");
                break;
            case PLUSASSIGN:
                ps.print("+=");
                break;
            case SUBASSIGN:
                ps.print("-=");
                break;
            case MULASSIGN:
                ps.print("*=");
                break;
            case DIVIDEASSIGN:
                ps.print("/=");
                break;
            case MODULOASSIGN:
                ps.print("%=");
                break;
            case LESSTHEN:
                ps.print("<");
                break;
            case LESSTHENEQUAL:
                ps.print("<=");
                break;
            case GREATERTHEN:
                ps.print(">");
                break;
            case GREATERTHENEQUAL:
                ps.print(">=");
                break;
            case EQUALEQUAL:
                ps.print("==");
                break;
            case NOTEQUAL:
                ps.print("!=");
                break;
        }
        expr2.print(ps);
        ps.print(")");
    }

    @Override
    public void check() {
        //Type Checking Done Here
        type = Compiler.expressionReturnTypeCheck(this);

        //Add Temporary Variables
        if(op != ASSIGN){
            Compiler.addTempararyVariable((Expr) this);
        }
        
    }

    @Override
    public void genCode() {
        List<Integer> compuondExprOps = Arrays.asList(PLUSASSIGN, SUBASSIGN, MULASSIGN, DIVIDEASSIGN, MODULOASSIGN);
        List<Integer> binaryOps = Arrays.asList(PLUS, SUB, MUL, DIVIDE, MODULO, LESSTHEN, LESSTHENEQUAL, GREATERTHEN, GREATERTHENEQUAL, EQUALEQUAL, NOTEQUAL);

        if(op == ASSIGN){
            expr1.genCode();
            expr2.genCode();

            System.out.println(expr1.value + "=" + expr2.value + ";");
            value = expr2.value;
        }else if(compuondExprOps.contains(op)){
            expr1.genCode();
            expr2.genCode();
            value = "_t" + Program.tempVarIndex2++;

            System.out.print(value + "=" + expr1.value);
            printExpression(op);
            System.out.print(expr2.value + ";\n");

            System.out.println(expr1.value + "=" + value + ";");
        }else if(binaryOps.contains(op)){
            expr1.genCode();
            expr2.genCode();
            value = "_t" + Program.tempVarIndex2++;

            System.out.print(value + "=" + expr1.value);
            printExpression(op);
            System.out.print(expr2.value + ";\n");
        }
    }

    private void printExpression(int op) {
        switch (op) {
            case PLUS:
                System.out.print("+");
                break;
            case SUB:
                System.out.print("-");
                break;
            case MUL:
                System.out.print("*");
                break;
            case DIVIDE:
                System.out.print("/");
                break;
            case MODULO:
                System.out.print("%");
                break;
            case ASSIGN:
                System.out.print("=");
                break;
            case PLUSASSIGN:
                System.out.print("+");
                break;
            case SUBASSIGN:
                System.out.print("-");
                break;
            case MULASSIGN:
                System.out.print("*");
                break;
            case DIVIDEASSIGN:
                System.out.print("/");
                break;
            case MODULOASSIGN:
                System.out.print("%");
                break;
            case LESSTHEN:
                System.out.print("<");
                break;
            case LESSTHENEQUAL:
                System.out.print("<=");
                break;
            case GREATERTHEN:
                System.out.print(">");
                break;
            case GREATERTHENEQUAL:
                System.out.print(">=");
                break;
            case EQUALEQUAL:
                System.out.print("==");
                break;
            case NOTEQUAL:
                System.out.print("!=");
                break;
        }
    }
}