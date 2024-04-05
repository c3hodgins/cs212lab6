#include "HodginsC_Lab6.h"

int main(){
    FILE* pInput;
    FILE* pOutput;
    char* string;    
    nodeType* newNode = NULL;

    openDataFiles(&pInput,"Input.txt",&pOutput,"Output.txt");

    PrintHeader(pOutput);

    stackType* stack = NULL;

    if (pInput != NULL){    
        //check if file opens correctly
        while (fgets(string, 40, pInput) != EOF){
            for (int i = 0;i <strlen(string);i++){
                if ((string[i] < 57)&&(string[i]>47)){
                    fprintf(pOutput,"%c",string[i]);
                }else{
                    if (string[i] = '('){
                        newNode = (nodeType*)malloc(sizeof(nodeType));
                        newNode->record.symbol = string[i];
                        push(stack,newNode);
                    }else if (string[i]  == ')'){
                        while((stack)->pTop->record.symbol != '('){
                            fprintf(pOutput,"%c",stack->pTop->record.symbol);
                            pop(stack);
                        }
                        pop(stack);
                    }else if ((string[i] == '+')&&(string[i] == '-')&&(string[i] == '/')&&(string[i] == '*')){
                        while(returnPriority(stack->pTop->record.symbol)>=returnPriority(string[i])){
                            fprintf(pOutput,"%c",stack->pTop->record.symbol);
                            newNode = (nodeType*)malloc(sizeof(nodeType));
                            newNode->record.symbol = string[i];
                            push(stack,newNode);
                        }
                    }
                }
                while(stack->pTop != NULL){
                    fprintf(pOutput,"%c",stack->pTop);
                    pop(stack->pTop);
                }
                fprintf(pOutput,"\n");
            }
        }
    }
}