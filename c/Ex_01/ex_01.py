#!/usr/bin/python
# -*- coding: utf-8 -*-
'''
 Problema 01

   Um pecuarista possui uma determinada quantia de bois, que possuem um identificador
   numerico (de 1 a n) cada um.

   Faça um programa que: 

 a.	receba o peso de cada boi, um por vez, e o armazene em um vetor. 
       Se o peso digitado for 0 significa que não há mais bois a serem digitados; 

 b.	mostre a lista de todos os bois com seus identificadores e também os 
       identificadores do boi mais gordo e do boi mais magro. 
       Se houver dois ou mais bois mais gordos ou mais magros mostrar o de 
       menor identificador; 

 c.	Faça o mesmo programa considerando que o número de bois é fixo e igual a dez.
'''

pesos = []

i = 0
peso = 1
while i < 10 and peso > 0:
    peso = input("Peso #"+(str)(i+1)+": ")
    i += 1
    if peso > 0:
        pesos.append(peso)

if len(pesos) == 0:
    print("Nenhum peso foi informado!")
    exit

pesos.sort()

i = 0
for p in pesos:
    if i==0:
        texto = "MENOR"
    elif i==len(pesos)-1:
        texto = "MAIOR"
    else:
        texto = ""
    print("#"+str(i+1)+" = "+str(p)+" "+texto)
    i += 1




