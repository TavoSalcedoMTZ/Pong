# Pong
Juego Pong Creado Para Cuarto Parcial de programacion

En este programa lo que hice fue:

1ro Creacion de Todas las figuras utilizadas dentro del Juego Pongo las 2 raquetas, la pelota, las lineas divisoras de pantalla, y los Scores
2do Estableci un ciclo condional utilizando las Herramientas del SFML para poder detectar las entradas de mi teclado y asi poder mover las posicion de las raquetas a traves del angulo y, tanto con el WS como Teclas Up y Down
3ro Cree un vector que almacena la velocidad de movimiento de la pelota y una variable de aumento para que cada vez que la pelota es colisonada por una de las 2 raquetas su velocidad vaya aumentando y al hacer un punto su velocidad se reinicie.
4to Creamos las variables de puntuacion y Score,  y estabecemos mla colision con los bordes de la pantalla haciendo que si la posicion de la pelota llega a igualar o intentar superar la anchura de la pantalla la posicion de la pelota se reinicie hacia el centro y se sume un punto dependiendo de que lado fue colisonado
5to Definimos las colision de la pelota y la raqueta haciendo que si esta sucede la velocidad de la pelota se invierte y aumenta la velocidad haciendo que la raqueta desvie la pelota de su trayectoria original y la invierta
6to Se limita la velocidad de fotogramas de la ventana a 60 ya que si no es establecida el juego correra a velocidad inestimadas.
7t0 Se actualizan los puntos del score y se Renderiza todos los elementos del juego, para por ultimo hacerle display.
