#aim:: to send letter 'p' over the serial port and blink led of arduino 
#for this we use the serialport gem 
#this serialport gem will send the letter 'p' over the serialport to the arduino board

require "serialport"

port_file= "/dev/ttyACM0" #in case of windows use COMi where is the port number
baud_rate= 9600

data_bits= 8
stop_bits= 1
parity= SerialPort::NONE

#now we will create the object of serialport
obj= SerialPort.new(port_file, baud_rate, data_bits, stop_bits, parity)
wait_time= 15

#it is just like a while loop
loop do
	obj.write "p"
	puts "Deepan, p"	
	sleep wait_time

end
