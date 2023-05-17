#include <iostream>
#include <fstream>
#include <sstream>
#include "lzw.h"
#include "decompressLZW.h"

void comprimirArquivo(const std::string &nomeArquivoEntrada, const std::string &nomeArquivoSaida)
{
    // Abrir o arquivo de entrada
    std::ifstream arquivoEntrada(nomeArquivoEntrada);
    if (!arquivoEntrada)
    {
        std::cerr << "Falha ao abrir o arquivo de entrada." << std::endl;
        return;
    }

    // Ler o conteúdo do arquivo de entrada
    std::string conteudoEntrada(
        (std::istreambuf_iterator<char>(arquivoEntrada)),
        (std::istreambuf_iterator<char>()));

    // Comprimir o conteúdo de entrada usando o LZW
    std::string conteudoComprimido = comprimirLZW(conteudoEntrada);

    // Abrir o arquivo de saída
    std::ofstream arquivoSaida(nomeArquivoSaida);
    if (!arquivoSaida)
    {
        std::cerr << "Falha ao abrir o arquivo de saida." << std::endl;
        return;
    }

    // Escrever o conteúdo comprimido no arquivo de saída
    arquivoSaida << conteudoComprimido;

    // Fechar os arquivos
    arquivoEntrada.close();
    arquivoSaida.close();

    std::cout << "Compressao concluida. Dados comprimidos gravados em " << nomeArquivoSaida << std::endl;
}

void descomprimirArquivo(const std::string &nomeArquivoEntrada, const std::string &nomeArquivoSaida)
{
    // Abrir o arquivo de entrada
    std::ifstream arquivoEntrada(nomeArquivoEntrada);
    if (!arquivoEntrada)
    {
        std::cerr << "Falha ao abrir o arquivo de entrada." << std::endl;
        return;
    }

    // Ler o conteúdo do arquivo de entrada
    std::string conteudoComprimido(
        (std::istreambuf_iterator<char>(arquivoEntrada)),
        (std::istreambuf_iterator<char>()));

    // Descomprimir o conteúdo de entrada usando o LZW
    std::string conteudoDescomprimido = descomprimirLZW(conteudoComprimido);

    // Abrir o arquivo de saída
    std::ofstream arquivoSaida(nomeArquivoSaida);
    if (!arquivoSaida)
    {
        std::cerr << "Falha ao abrir o arquivo de saida." << std::endl;
        return;
    }

    // Escrever o conteúdo descomprimido no arquivo de saída
    arquivoSaida << conteudoDescomprimido;

    // Fechar os arquivos
    arquivoEntrada.close();
    arquivoSaida.close();

    std::cout << "Descompressao concluida. Dados descomprimidos gravados em " << nomeArquivoSaida << std::endl;
}

int main()
{
    int escolha;
    std::string nomeArquivoEntrada, nomeArquivoSaida;

    while (true)
    {
        std::cout << "Menu:\n"
                  << "1. Comprimir arquivo\n"
                  << "2. Descomprimir arquivo\n"
                  << "0. Sair\n"
                  << "Digite sua escolha: ";
        std::cin >> escolha;

        if (escolha == 0)
        {
            break;
        }
        else if (escolha == 1)
        {
            std::cout << "Digite o nome do arquivo a ser compimido: ";
            std::cin >> nomeArquivoEntrada;
            std::cout << "Digite o nome do arquivo de saida: ";
            std::cin >> nomeArquivoSaida;
            comprimirArquivo(nomeArquivoEntrada, nomeArquivoSaida);
        }
        else if (escolha == 2)
        {
            std::cout << "Digite o nome do arquivo a ser descomprimido: ";
            std::cin >> nomeArquivoEntrada;
            std::cout << "Digite o nome do arquivo de saida: ";
            std::cin >> nomeArquivoSaida;
            descomprimirArquivo(nomeArquivoEntrada, nomeArquivoSaida);
        }
        else
        {
            std::cout << "Escolha invalida.\n";
        }
        std::cout << std::endl;
    }

    return 0;
}
