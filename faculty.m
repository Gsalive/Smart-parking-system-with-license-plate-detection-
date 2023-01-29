function faculty

global arduino


%arduino=serialport('COM8',9600)
%fopen(arduino)              
                fprintf(arduino,'#    Faculty')
                dataReceive = fscanf(arduino);
                pause(3);
                fprintf(arduino,'#');
                fprintf(arduino,'#   Turn Left')
                pause(3);
                fprintf(arduino,'#');

               
end