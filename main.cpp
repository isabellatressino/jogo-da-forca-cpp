#include <iostream>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <iomanip>

#define RESET "\033[0m"
#define RED "\033[31m"     
#define GREEN "\033[32m"     
#define YELLOW "\033[33m"     
#define BLUE "\033[34m"     
#define MAGENTA "\033[35m"     
#define CYAN "\033[36m"     
#define RESET "\033[0m"
#define RED_BACKGROUND "\033[41m"
#define GREEN_BACKGROUND "\033[42m"
#define MAGENTA_BACKGROUND "\033[45m"
#define CYAN_BACKGROUND "\033[46m"

#define TAM 12
#define TAMCat 5
using namespace std;

typedef struct{
    char categoria[15];
    char dificuldade[6];
    char BancoPalavras[TAM][21];
}categorias;

void cabecalho(){
    cout << MAGENTA << "\n\n";
    cout << "------------------------------" <<  endl;
    cout << MAGENTA_BACKGROUND << "         JOGO DA FORCA        " << RESET << endl;
    cout << MAGENTA << "------------------------------\n" << RESET  << endl;
}

int boas_vindas(categorias c[TAMCat]){
    int escolha;
    cabecalho();
    cout << MAGENTA << left << setw(15) << "Categoria" << left << setw(12) << "Dificuldade" << RESET << endl;
    for(int i=0;i<TAMCat;i++){
        cout << MAGENTA << i+1 << "- ";
        cout << BLUE << left << setw(15) << c[i].categoria;
        cout << CYAN << left << setw(6) << c[i].dificuldade << RESET << endl; 
    }
    do{
        cout << MAGENTA << "\nEscolha uma categoria: " << RESET;
        cin >> escolha;
        if(escolha <1 || escolha >TAMCat)
            cout << RED << "Escolha uma categoria valida." << RESET << endl;
    } while(escolha <1 || escolha >TAMCat);
    return escolha;
}

void sortear_palavra(char Palavra[], char bd[][21], char Vet_acertos[]){
    int tamanho, i;
    srand(time(0));
    i = rand() % TAM;
    strcpy(Palavra,bd[i]);
    
    tamanho = strlen(Palavra);
    for(int j=0;j<tamanho;j++)
        Vet_acertos[j] = '_';
    
    Vet_acertos[tamanho] = '\0';
}

void desenha_forca(int k, char Vet_erros[20], char Vet_acertos[20]){
    cabecalho();
    switch (k){
        case 0:
            cout << YELLOW <<  "   +----------+" << endl;
            cout <<  "   |          |" << endl;
            cout <<  "   |" << endl;
            cout <<  "   |" << endl;
            cout <<  "   |" << endl;  
            cout <<  "   |" << endl;
            cout <<  "   |" << endl;    
            cout <<  "   |" << endl;  
            cout <<  "   |" << endl; 
            cout <<  "   |" << endl;    
            cout <<  "   |" << endl;   
            cout <<  "   |" << endl; 
            cout <<  "   |" << endl; 
            cout <<  "   |" << endl;
            cout << "-----------" << RESET << endl;
            break;
        case 1:
            cout << YELLOW << "+----------+" << endl;
            cout << YELLOW << "|          |" << RESET << endl;
            cout << YELLOW << "|     " << RESET << "  +------+" << endl;
            cout << YELLOW << "|     " << RESET << "  | " << BLUE <<  "^  ^ " << RESET "|" << endl;
            cout << YELLOW << "|     " << RESET << "  |   " << RED << "-" << RESET <<"  |" << endl;  
            cout << YELLOW << "|     " << RESET << "  +------+" << endl;
            cout << YELLOW << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "-----------" << RESET << endl;
            break;
        case 2:
            cout << YELLOW << "+----------+" << endl;
            cout << YELLOW << "|          |" << RESET << endl;
            cout << YELLOW << "|      " << RESET << " +------+" << endl;
            cout << YELLOW << "|      " << RESET << " | " << BLUE << "^  ^ " << RESET << "|" << endl;
            cout << YELLOW << "|      " << RESET << " |   " << RED << "-  " << RESET << "|" << endl;  
            cout << YELLOW << "|      " << RESET << " +------+" << endl;
            cout << YELLOW << "|      " << RESET << "     |" << endl;
            cout << YELLOW << "|      " << RESET << "     |" << endl;
            cout << YELLOW << "|      " << RESET << "     |" << endl;
            cout << YELLOW << "|      " << RESET << "     |" << endl;
            cout << YELLOW << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "-----------" << RESET << endl;
            break;
        case 3:
            cout << YELLOW << "+----------+" << endl;
            cout << "|          |" << RESET << endl;
            cout << YELLOW << "|   " << RESET << "    +------+" << endl;
            cout << YELLOW << "|   " << RESET << "    | " << BLUE << ".  . " << RESET << "|" << endl;
            cout << YELLOW << "|   " << RESET << "    |   " << RED << "- " << RESET << " |" << endl;  
            cout << YELLOW << "|   " << RESET << "    +------+" << endl;
            cout << YELLOW << "|   " << RESET << "        |" << endl;
            cout << YELLOW << "|   " << RESET << "      / |" << endl;
            cout << YELLOW << "|   " << RESET << "     /  |" << endl;
            cout << YELLOW << "|   " << RESET << "        |" << endl;
            cout << YELLOW << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "-----------" << RESET << endl;
            break;
        case 4:
            cout << YELLOW << "+----------+" << endl;
            cout << "|          |" << RESET << endl;
            cout << YELLOW << "| " << RESET << "      +------+" << endl;
            cout << YELLOW << "| " << RESET << "      | " << BLUE << "O  O" << RESET << " |" << endl;
            cout << YELLOW << "| " << RESET << "      |   " << RED << "- " << RESET << " |" << endl;  
            cout << YELLOW << "| " << RESET << "      +------+" << endl;
            cout << YELLOW << "| " << RESET << "          |" << endl;
            cout << YELLOW << "| " << RESET << "        / | \\" << endl;
            cout << YELLOW << "| " << RESET << "       /  |  \\" << endl;
            cout << YELLOW << "| " << RESET << "          |" << endl;
            cout << YELLOW << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "-----------" << RESET << endl;
            break;
        case 5:
            cout << YELLOW << "+----------+" << endl;
            cout << "|          |" << RESET << endl;
            cout << YELLOW << "| " << RESET << "      +------+" << endl;
            cout << YELLOW << "| " << RESET << "      | " << BLUE << "T  T" << RESET << " |" << endl;
            cout << YELLOW << "| " << RESET << "      |  " << RED << " -  " << RESET <<"|" << endl;  
            cout << YELLOW << "| " << RESET << "      +------+" << endl;
            cout << YELLOW << "| " << RESET << "          |" << endl;
            cout << YELLOW << "| " << RESET << "        / | \\" << endl;
            cout << YELLOW << "| " << RESET << "       /  |  \\" << endl;
            cout << YELLOW << "| " << RESET << "          |" << endl;
            cout << YELLOW << "| " << RESET << "         / " << endl;
            cout << YELLOW << "| " << RESET << "        /   " << endl;
            cout << YELLOW << "| " << RESET << "       /     " << endl;
            cout << YELLOW << "|" << endl;
            cout << "-----------" << RESET << endl;
            break;
        case 6:
            cout << YELLOW << "+----------+" << endl;
            cout << "|          |" << RESET << endl;
            cout << YELLOW << "|  " << RESET << "     +------+" << endl;
            cout << YELLOW << "|  " << RESET << "     | " << BLUE << "X  X" << RESET << " |" << endl;
            cout << YELLOW << "|  " << RESET << "     |  " << RED << " - " << RESET << " |" << endl;  
            cout << YELLOW << "|  " << RESET << "     +------+" << endl;
            cout << YELLOW << "|  " << RESET << "         |" << endl;
            cout << YELLOW << "|  " << RESET << "       / | \\" << endl;
            cout << YELLOW << "|  " << RESET << "      /  |  \\" << endl;
            cout << YELLOW << "|  " << RESET << "         |" << endl;
            cout << YELLOW << "|  " << RESET << "        / \\" << endl;
            cout << YELLOW << "|  " << RESET << "       /   \\" << endl;
            cout << YELLOW << "|  " << RESET << "      /     \\" << endl;
            cout << YELLOW << "|" << endl;
            cout << "-----------" << RESET << endl;
            break;
    }

    cout << endl;

    for (int i = 0; i < strlen(Vet_acertos); i++) {
        if (Vet_acertos[i] != '_') 
            cout << GREEN << Vet_acertos[i] << " " << RESET;
        else 
            cout << "_ "; 
    }

    cout << RED << "\n\nErros: ";
    for(int i=0;i<strlen(Vet_erros);i++){
        if(Vet_erros[i] != '\0')
            cout << Vet_erros[i] << " ";
    }
    cout << RESET;
}

int jogada(char Palavra[], char Vet_acertos[], char Vet_erros[], int *erros, int *acertos){
    int flag=0;
    char letra;

    system("cls");

    desenha_forca(*erros, Vet_erros, Vet_acertos);

    cout << endl;
    do{
        cout << MAGENTA << "\nLetra: " << RESET;
        cin >> letra;
        if(letra == '*') return 0;
        letra = toupper(letra);
    }while(!isalpha(letra));
    for(int i = 0; i < strlen(Palavra); i++){
        if(Palavra[i] == letra){
            Vet_acertos[i] = Palavra[i];
            flag = 1;
            (*acertos)++;
        }
    }
    if(flag==0){
        Vet_erros[*erros] = letra;
        (*erros)++;
    }
    
    desenha_forca(*erros, Vet_erros, Vet_acertos);

    if(*erros == 6) return -1;
    if(*acertos == strlen(Palavra)) return 1;

    return jogada(Palavra, Vet_acertos, Vet_erros, erros, acertos);
}

int main(){ 

    categorias c[TAMCat] = {
        "Frutas", "*", {"ACEROLA", "ABACATE","BANANA","CARAMBOLA","DAMASCO","FIGO", "GRAVIOLA", "JAMBO","LICHIA", "LIMAO", "MELANCIA", "MELAO"},
        "Animais", "**", {"ALBATROZ", "BALEIA","DROMEDARIO","FLAMINGO","GUAXINIM","JAVALI", "LEMURE", "ORNINTORRINCO","PONEI", "RATAZANA", "SERPENTE", "ZEBRA"},
        "Paises", "***", {"ARGENTINA", "BRASIL","ESPANHA","GUATEMALA","ISRAEL","LITUANIA", "MARROCOS", "PALESTINA","RUANDA", "SENEGAL", "TAJIQUISTAO", "UZUBEQUISTAO"},
        "Insetos", "****", {"BORRACHUDO","CIGARRA", "ESCARAVELHO","GAFANHOTO","LIBELULA","MAMANGABA","MANDROVA","PERCEVEJO", "PIRILAMPO", "SIRIRI","SOLDADINHO","TANAJURA"},
        "Profissoes", "*****", {"ACUPUNTURISTA", "BALCONISTA","CAFEICULTOR","DESEMBARGADOR","FONOAUDIOLOGO","INSTRUMENTISTA", "NEUROPSICOLOGO", "OCEANOGRAFO","PAISAGISTA", "SOLDADOR", "SOMMELIER", "TOPOGRAFO"} };

    char palavra[21], acertos[30], erros[7];
    int contAcertos=0, contErros=0, ret, cat;

    char opc = 'S';

    while(opc != 'N'){

        system("cls");

        for(int i = 0; i < 7; i++) {
            erros[i] = '\0';
        }
        
        cat = boas_vindas(c);
        switch (cat){
            case 1:
                sortear_palavra(palavra,c[cat-1].BancoPalavras,acertos);
                break;
            case 2:
                sortear_palavra(palavra,c[cat-1].BancoPalavras,acertos);
                break;
            case 3:
                sortear_palavra(palavra,c[cat-1].BancoPalavras,acertos);
                break;
            case 4:
                sortear_palavra(palavra,c[cat-1].BancoPalavras,acertos);
                break;
            case 5: 
                sortear_palavra(palavra,c[cat-1].BancoPalavras,acertos);
                break;
        }

        contAcertos = contErros = 0;

        ret = jogada(palavra,acertos,erros,&contErros,&contAcertos);
        system("cls");
        cabecalho();
        if(ret == 0){
            cout << CYAN_BACKGROUND << " VOCE DESISTIU " << RESET << endl;
            cout << "A palavra era: " << CYAN << palavra << RESET;
        }
        else if(ret == -1){
            cout << RED_BACKGROUND << " VOCE PERDEU " << RESET << endl;
            cout << "A palavra era: " << RED << palavra << RESET << endl;
        }
        else{
            cout << GREEN_BACKGROUND << " VOCE GANHOU " << RESET << endl;
            cout << "A palavra era: " << GREEN << palavra << RESET << endl; 
        }

        cout << "\n\nDeseja jogar novamente? [S/N] ";
        cin >> opc;
        opc = toupper(opc);

        if(opc == 'N')
            cout << "Encerrado." << endl;

    }

    return 0;

}