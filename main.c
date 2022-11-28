/*
Autores - Allan Guilherme Gomes Pego, Thiago Cardozo e Pedro Augusto Etelvino
Albuquerque 
Objetivo - Apresentar um programa em C que calcula o valor a ser
pago de consumo de água.
  */
#include <stdio.h>

float faixa1(float vet[7]) // Faixa 1 detalha o consumo para zero metros cúbicos

{
  float fixaA = 17.61; // taxa fixa de água
  float fixaE = 13.03; // taxa fixa de esgoto
  float fixaTotal = fixaA + fixaE;
  printf("FIXA            taxa de esgoto R$%.3f        taxa de água R$%.3f\n",
         fixaE, fixaA);
  printf("Faixa de consumo     Gasto em m³  Valor na faixa\n");

  vet[0] = fixaTotal;
  return 0;
}

float faixa2(float consumo, float vet[7])
{
  if (consumo > 0) {
    faixa1(vet);
    vet[1] = (1.820 + 1.350) * consumo;
    printf("Faixa entre 0 e 5      %.3f      R$%.3f\n", consumo, vet[1]);
    return 0;
  } else {
    faixa1(vet);
    vet[1] = (1.820 + 1.350) * consumo;
    printf("Faixa entre 0 e 5      %.3f      R$%.3f\n", consumo, vet[1]);
    return 0;
  }
}

float faixa3(float consumo, float vet[7]) {
  float cfaixa = consumo - 5;
  if (consumo > 5) {
    faixa2(5, vet);
    vet[2] = (3.886 + 2.876) * cfaixa;
    printf("Faixa entre 5 e 10     %.3f      R$%.3f\n", cfaixa, vet[2]);
    return 0;
  } else {
    faixa2(consumo, vet);
    cfaixa = 0;
    vet[2] = (3.886 + 2.876) * cfaixa;
    printf("Faixa entre 5 e 10     %.3f      $%.3f\n", cfaixa, vet[2]);
    return 0;
  }
}

float faixa4(float consumo, float vet[7]) {
  float cfaixa = consumo - 10;
  if (consumo > 10) {
    faixa3(10, vet);
    vet[3] = (6.023 + 4.457) * cfaixa;
    printf("Faixa entre 10 e 15    %.3f      R$%.3f\n", cfaixa, vet[3]);
    return 0;
  } else {
    faixa3(consumo, vet);
    cfaixa = 0;
    vet[3] = (6.023 + 4.457) * cfaixa;
    printf("Faixa entre 10 e 15     %.3f     R$%.3f\n", cfaixa, vet[3]);
    return 0;
  }
}

float faixa5(float consumo, float vet[7]) {
  float cfaixa = consumo - 15;
  if (consumo > 15) {
    faixa4(15, vet);
    vet[4] = (8.222 + 6.084) * cfaixa;
    printf("Faixa entre 15 e 20    %5.3f      R$%.3f\n", cfaixa, vet[4]);
    return 0;
  } else {
    faixa4(consumo, vet);
    cfaixa = 0;
    vet[4] = (8.222 + 6.084) * cfaixa;
    printf("Faixa entre 15 e 20    %.3f      R$%.3f\n", cfaixa, vet[4]);
    return 0;
  }
}

float faixa6(float consumo, float vet[7]) {
  float cfaixa = consumo - 20;
  if (consumo > 20) {
    faixa5(20, vet);
    vet[5] = (10.458 + 7.739) * cfaixa;
    printf("Faixa entre 20 e 40    %.3f     R$%.3f\n", cfaixa, vet[5]);
    return 0;
  } else {
    faixa5(consumo, vet);
    cfaixa = 0;
    vet[5] = (10.458 + 7.739) * cfaixa;
    printf("Faixa entre 20 e 40     %.3f      R$%.3f\n", cfaixa, vet[5]);
    return 0;
  }
}
/*
nestas faixas a função será acionada recebendo o consumo, verifica se há consumo nesta faixa,caso haja, efetua o cálculo, salva o resultado no vetor e repassa o valor máximo para a função da próxima faixa; caso não haja, grava 0 no vetor e repassa o consumo para a próxima faixa. Nas próximas faixas haverá a mesma estrutura, com exceção da faixa 1. 
 */
float faixa7(float consumo, float vet[7])
{
  float cfaixa = consumo - 40;
  if (consumo > 40) {
    faixa6(40, vet);
    vet[6] = (12.759 + 9.441) * cfaixa;
    printf("Faixa acima de 40      %.3f     R$%.3f\n", cfaixa, vet[6]);
    return 0;
  } else {
    faixa6(consumo, vet);
    cfaixa = 0;
    vet[6] = (12.759 + 9.441) * cfaixa;
    printf("Faixa acima de 40      %.3f     R$%.3f\n", cfaixa, vet[6]);
    return 0;
  }
}
float valorDaConta(float vet[7]) 
{
  float soma = 0;
  for (int c = 0; c < 7; c++) {
    soma += vet[c];
  }
  return soma;
}
int main(void) {
  float vet[7];//declara o vetor que armazenará os valores em cada faixa
  float consumo;//declara o consumo em metros cúbicos
  float valor;
  printf("Informe o consumo em metros cúbicos:\n");
  scanf("%f", &consumo); // lê o consumo da conta

  if (consumo < 0) // filtra se o valor informado está fora do domínio da função
                   // e apresenta mensagem de erro.
  {
    printf("valor informado incorretamente");
  } else {
    faixa7(consumo, vet);//aciona a função da faixa 7 com o consumo e o vetor como parâmetro
  }
  valor = valorDaConta(vet);//aciona a função que soma os valores salvos no vetor 
  printf("Valor a pagar nesta fatura: R$%.3f", valor);
  return 0;
}