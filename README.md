# Algoritmo LZW usando árvore binária

## Compilando o projeto

```terminal
g++ main.cpp lzw.cpp binarytree.cpp decompressLZW.cpp -O2 -o1 lzw
```

## Como testar o projeto

- Criar um arquivo Input.txt
- Rodar o programa e utilizar a opção 1
- escrever o nome do arquivo (input.txt) no terminal
- escrever o nome desejado para o arquivo de output (comprimido). Ex.: output.txt

## Problemas

O clássico problema dos algoritmos baseados em dicionários é a memória necessária. Quanto mais lemos dados do arquivo, mais sequências armazenamos no dicionário, e com isso, necessitamos de mais memória. O outro problema que isso causa é de espaço de endereçamento: os códigos das entradas no dicionário crescem junto com ele (em geral ocupam log2(N) bits , onde **N** é o tamanho, ou número de entradas, do dicionário). Várias abordagens podem ser adotadas para lidar com esse problema, as mais simples são:

- Congelamento do dicionário (quando o dicionário atinge o tamanho limite, ele fica "congelado" e mais nenhuma entrada pode ser adicionada nele).
- Esvaziamento (o dicionário é esvaziado e a compressão começa toda de novo). Essa técnica pressupõe que é mais vantajoso usar a redundância local que a redundância global para a compressão. corresponde a separar o arquivo em "blocos" comprimidos separadamente.
- Uso de uma política de esvaziamento que seja comum tanto ao compressor quanto ao descompressor (apagar entradas mais antigas, por exemplo).

Outro problema, esse específico do LZ78, é o crescimento lento do dicionário. Devido a característica de inserir as cadeias no dicionário assim que um único caractere quebra a sequência faz com que o dicionário cresça de forma lenta e só se torne realmente útil depois de bastante informação lida. Esse problema torna o LZ78 e seus derivados pouco apropriado para comprimir quantidades muito pequenas de dados. A abordagem dada pelo LZ77 pode ser útil nos casos onde o crescimento lento do dicionário venha a reduzir a compressão.

Fonte(s): [1](https://pt.wikipedia.org/wiki/LZW#problemas), [2](https://pt.wikipedia.org/wiki/LZ78#Problemas)

## Limitações

O algoritmo é simples de implementar e tem potencial para um rendimento muito bom em dados com padrões repetitivos. No entanto, ele tem algumas limitações, como o fato de que ele não funciona bem com dados aleatórios ou com padrões que não se repetem com frequência.
Fonte(s): [1](https://pt.wikipedia.org/wiki/LZW), [2](https://acervolima.com/tecnica-de-compressao-lzw-lempel-ziv-welch/), [3](http://multimedia.ufp.pt/codecs/compressao-sem-perdas/codificacao-baseada-em-dicionarios/lzw/)
