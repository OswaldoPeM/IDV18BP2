'''escribir un programa el cual reciba como input, una cadena un string que se componga de 2 numero y un operador separados por espacios.
ejemplo (2 + 5) el programa debe ejecutar la operacion segun el operador, los operadores permitidos son (sunma(+,-), multiplicacion(*), sivicion(/), residuo(%), potencia(^))'''
def main():
	operacion = input("Hola querido usuario, si quieres realizar una operacion matematica como: suma, resta, multiplicacion, division, residuo o potencia. ingrese su operacion de dos numeros con espacio entre el operador: ")
	operador = operacion.split(" ")
	
	if (operador[1] == "+"):
		result = int(operador[0]) + int(operador[2])

	if  (operador[1] == "-"):
		result = int(operador[0]) - int(operador[2])

	if  (operador[1] == "*"):
		result = int(operador[0]) * int(operador[2])

	if  (operador[1] == "/"):
		result = int(operador[0]) / int(operador[2])
		
	if  (operador[1] == "^"):
		result = int(operador[0]) ** int(operador[2])

	if  (operador[1] == "%"):
		result = int(operador[0]) % int(operador[2])



	print("El resultado es " + float(result))

if __name__ == "__main__":
	main()