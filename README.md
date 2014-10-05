bateria-atmega
==============

INFO
----
Por ahora es la salida del circuito es midi, usando el arduino podemos salir directo a usb.
Eventualmente tendra salida usb o ambas, para el seguimiento vamos a usar los [issues](https://github.com/JuanMsanchez/bateria-atmega/issues).

FZZ
---
	- bata_midi_arduino.fzz ( protoboard + arduino )	
	- bata_midi_deploy.fzz ( protoboard + atmega328 )	
	- bata_midi_pcb.fzz ( circuito impreso salida midi )	

*Los archivos fzz se abren con [Fritzing]( http://fritzing.org/download/ )

APP
---
	- send_bata_midi.ino ( para quemar en el atmega )

DOCS
----
Lo mas sencillo es usar [Hairles MIDI Serial](http://projectgus.github.io/hairless-midiserial/)
Tiene una version para linux, osx y windows.

De todas formas para probarlo en su momento use [ttymidi](http://www.varal.org/ttymidi/), [timidity](http://timidity.sourceforge.net/) y [qsynth](http://qsynth.sourceforge.net/qsynth-index.html) y anduvo todo bien.
Dejo los links de cada proyecto y los pasos que segui. En cada link hay documentacion extra, la mas interesante para lo que estamos haciendo es la de TTYMIDI.

		ttymidi -s /dev/ttyACM0 -v -n arduino_midi -b 115200

		timidity -iA

		aconnect -i

		aconnect -o

		aconnect 128:0 130:0

		qsynth

