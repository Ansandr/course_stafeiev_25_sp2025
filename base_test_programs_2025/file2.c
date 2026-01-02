#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

int data[8192] = {0};
int contextStack[8192] = {0}, contextStackIndex = 0;
int opStack[8192] = {0}, opStackIndex = 0, opTemp = 0;
int lastBindDataIndex = 0;

int main() {
    contextStackIndex = 0;
    opStackIndex = 0;
    opTemp = 0;
    lastBindDataIndex = 0;

    //";"

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"read"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"read"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"read"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"if"

    //"AB1"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"AC2"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"gt"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //"AB1"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"AD3"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"gt"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //"and"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "if")
    if (opTemp == 0) goto LABEL__AFTER_THEN_0000000002BD2F10;

    //"AB1"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //":>"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "then"-part of if-operator)
    opTemp = 1;
LABEL__AFTER_THEN_0000000002BD2F10:

    //"else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_0000000002BD5050;

    //"if"

    //"AC2"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"AB1"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"gt"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //"AC2"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"AD3"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"gt"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //"and"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //"{"

    //"AC2"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //":>"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"}"

    //"else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_0000000002BDA370;

    //"AD3"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //":>"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "else")
LABEL__AFTER_ELSE_0000000002BDA370:

    //";"

    //"}"

    //null statement (non-context)

    //"AE4"
    opStack[++opStackIndex] = opTemp = data[0x00000010];

    //"write"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"if"

    //"AB1"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"AC2"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"=="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"AB1"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"AD3"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"=="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"and"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex]; --opStackIndex;

    //"AC2"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"AD3"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"=="
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"and"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "if")
    if (opTemp == 0) goto LABEL__AFTER_THEN_0000000002BE2870;

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"write"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "then"-part of if-operator)
    opTemp = 1;
LABEL__AFTER_THEN_0000000002BE2870:

    //"else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_0000000002BE4588;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"write"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "else")
LABEL__AFTER_ELSE_0000000002BE4588:

    //"if"

    //"AB1"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"lt"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //"AC2"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"lt"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //"or"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] || opStack[opStackIndex]; --opStackIndex;

    //"AD3"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"lt"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //"or"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] || opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "if")
    if (opTemp == 0) goto LABEL__AFTER_THEN_0000000002BEA0F8;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"-"
    opTemp = opStack[opStackIndex - 1] -= opStack[opStackIndex]; --opStackIndex;

    //"write"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "then"-part of if-operator)
    opTemp = 1;
LABEL__AFTER_THEN_0000000002BEA0F8:

    //"else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_0000000002BEC660;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"write"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "else")
LABEL__AFTER_ELSE_0000000002BEC660:

    //"if"

    //"AB1"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"AC2"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"AD3"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"add"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"lt"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //"not"
    opTemp = opStack[opStackIndex] = !opStack[opStackIndex];

    //null statement (non-context)

    //after cond expresion (after "if")
    if (opTemp == 0) goto LABEL__AFTER_THEN_0000000002BF0D08;

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"write"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "then"-part of if-operator)
    opTemp = 1;
LABEL__AFTER_THEN_0000000002BF0D08:

    //"else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_0000000002BF2A20;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"write"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "else")
LABEL__AFTER_ELSE_0000000002BF2A20:

    return 0;
}