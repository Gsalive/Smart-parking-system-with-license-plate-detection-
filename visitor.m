function visitor

global arduino

                
                
                fprintf(arduino,'#   EMERGENCY!!!')
                dataReceive = fscanf(arduino);
                pause(3);
                fprintf(arduino,'#');
                fprintf(arduino,'#    AMBULANCE')
                pause(3);
                fprintf(arduino,'#');
                 
end