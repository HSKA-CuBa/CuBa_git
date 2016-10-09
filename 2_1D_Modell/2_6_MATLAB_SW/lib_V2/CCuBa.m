classdef CCuBa < handle
    properties
        mClient
        mProxy
    end
    
    methods
        function this = CCuBa()
            this.mClient = tcpip('localhost', 40000,...
                                 'NetworkRole', 'Client',...
                                 'Terminator', '');
            this.mClient.ByteOrder              = 'littleEndian';
            this.mProxy  = CProxy(this.mClient);
        end
        function connect(this)
            fopen(this.mClient); 
        end
        function disconnect(this)
             fclose(this.mClient);
        end
    end
    
end

