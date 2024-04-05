#include "HodginsC_Lab6.h"

int main(){
    FILE* pInput = NULL;
    FILE* pOutput = NULL;
    char string[40];    
    nodeType* newNode = NULL;

    openDataFiles(&pInput,"Input.txt",&pOutput,"Output.txt");

    PrintHeader(pOutput);

    stackType stack;
    stack.pTop = NULL;
    if (pInput != NULL)
    {   
        //check if file opens correctly
        while (fgets(string, 40, pInput) != NULL)
        {
            for (int index = 0; index <strlen(string); index++){
                if ((string[index] != '\n')&&(string[index] != '\0')&&(string[index] != 13)&&(string[index] != 10))
                {
                    if ((string[index] < 57)&&(string[index]>47))
                    {
                        fprintf(pOutput,"%c ",string[index]);
                    }else
                    {
                        if (string[index] == '(')
                        {
                            newNode = (nodeType*)malloc(sizeof(nodeType));
                            newNode->record.symbol = string[index];
                            newNode->pNext = NULL;
                            push(&stack,newNode);
                        }else if (string[index]  == ')')
                        {
                            while((stack.pTop->record.symbol != '(')&&(stack.pTop !=NULL))
                            {
                                fprintf(pOutput,"%c ",stack.pTop->record.symbol);
                                pop(&stack);
                            }
                            pop(&stack);
                        }else if ((string[index] == '+')||(string[index] == '-')||(string[index] == '/')||(string[index] == '*'))
                        {
                            while(returnPriority(stack.pTop->record.symbol)>=returnPriority(string[index]))
                            {
                                fprintf(pOutput,"%c ",stack.pTop->record.symbol);
                                pop(&stack);
                            }
                            newNode = (nodeType*)malloc(sizeof(nodeType));
                            newNode->record.symbol = string[index];
                            push(&stack,newNode);
                        }
                    }
                }
            }
            fprintf(pOutput,"\n");
        }
        while((stack).pTop != NULL){
            fprintf(pOutput,"%c ",stack.pTop->record.symbol);
            pop(&stack);
        }
    }
    closeDataFiles(&pInput,&pOutput);
}
