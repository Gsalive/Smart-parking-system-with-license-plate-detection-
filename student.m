function MATLAB_ARDUINO_LCD2

global arduino



                fprintf(arduino,'#    Student')
                dataReceive = fscanf(arduino);
                pause(3);
                fprintf(arduino,'#');
                fprintf(arduino,'#   Turn Right')
                pause(3);
                fprintf(arduino,'#');
                 
end