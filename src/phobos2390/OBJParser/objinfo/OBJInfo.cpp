#include <iostream>
#include <fstream>
#include <algorithm>
#include <OBJParser/Parser.h>
#include <OBJParser/Scanner.h>
#include <OBJParser/Stream.h>
#include <OBJParser/OBJData.h>

int main(int argc, char** argv) 
{
    int err_code = 0;
    if(argc == 2)
    {
        ifstream in;
        in.open(argv[1]);
        Stream stream(in, std::cout);
        Parser parser;
        Scanner scanner(stream, parser);
        try
        {
            scanner.start();
            parser.parse();
            Data::OBJData* data = parser.getData();
            if(data != 0)
            {
                std::for_each
                    ( data->getObjectsBegin()
                    , data->getObjectsEnd()
                    ,[](Data::ModelObject& object)
                    {
                        std::cout << "OBJECT: " << object.getIdentifier() << "\n";
                        std::for_each
                            ( object.getGroupsBegin()
                            , object.getGroupsEnd()
                            ,[](Data::Group& group)
                            {
                                std::cout << " Material: " << group.getMaterial() << "\n";
                                std::cout << " Faces: " << std::distance(group.getFacesBegin(), group.getFacesEnd()) << "\n";
                            });
                    });
            }
        }
        catch (std::string s)
        {
            std::cout << "Exeption caught: " << s << "\n";
        }
    }
    else
    {
        std::cout << "Usage: ./objinfo file.obj\n";
        err_code = -1;
    }
    return err_code;
}

