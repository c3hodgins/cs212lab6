#include "HodginsC_Lab6.h"

int main(){
    FILE* pInput;
    FILE* pOutput;
    char* string;    
    nodeType* newNode = NULL;

    openDataFiles(&pInput,"Input.txt",&pOutput,"Output.txt");

    stackType* stack = NULL;

    if (pInput != NULL){
        //check if file opens correctly
            while (fgets(string, 40, pInput) != EOF){
                // newNode = (nodeType*)malloc(sizeof(nodeType));
                // newNode->record.symbol = symbol;
                // push(stack,newNode);
                for (int i = 0;i <strlen(string);i++){
                    if ((string[i] < 57)&&(string[i]>47)){
                        fprintf(pOutput,"%c",string[i]);
                    }else 
                        if (string[i] = '('){
                            newNode = (nodeType*)malloc(sizeof(nodeType));
                            newNode->record.symbol = string[i];
                            push(stack,newNode);
                        }else if (string[i]  == ')'){
                            while((stack)->pTop->record.symbol != '('){
                                printf(pOutput,"%c",stack->pTop->record.symbol);
                                pop(stack);
                            }
                        }else if (string[i] == '+')
                }

            }
	}
	else{
		//print if file doesnt open corrrectly
		printf("File open unsuccessful");	
	}
}

    }
}