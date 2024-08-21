pushd %~dp0

protoc.exe -I=./ --cpp_out=./ ./Enum.proto
protoc.exe -I=./ --cpp_out=./ ./Struct.proto
protoc.exe -I=./ --cpp_out=./ ./Protocol.proto

protoc.exe -I=./ --csharp_out=./ ./Enum.proto
protoc.exe -I=./ --csharp_out=./ ./Struct.proto
protoc.exe -I=./ --csharp_out=./ ./Protocol.proto

IF ERRORLEVEL 1 PAUSE

XCOPY /Y Enum.pb.h "../../../Server"
XCOPY /Y Enum.pb.cc "../../../Server"
XCOPY /Y Struct.pb.h "../../../Server"
XCOPY /Y Struct.pb.cc "../../../Server"
XCOPY /Y Protocol.pb.h "../../../Server"
XCOPY /Y Protocol.pb.cc "../../../Server"

XCOPY /Y Enum.pb.h "../../../DummyClient"
XCOPY /Y Enum.pb.cc "../../../DummyClient"
XCOPY /Y Struct.pb.h "../../../DummyClient"
XCOPY /Y Struct.pb.cc "../../../DummyClient"
XCOPY /Y Protocol.pb.h "../../../DummyClient"
XCOPY /Y Protocol.pb.cc "../../../DummyClient"

XCOPY /Y Enum.cs "C:\Users\User\Documents\GitHub\Server Connect\Assets\Scripts\Packet\Protocol"
XCOPY /Y Struct.cs "C:\Users\User\Documents\GitHub\Server Connect\Assets\Scripts\Packet\Protocol"
XCOPY /Y Protocol.cs "C:\Users\User\Documents\GitHub\Server Connect\Assets\Scripts\Packet\Protocol"


XCOPY /Y Enum.cs "C:\Users\User\Documents\GitHub\SunNight_Ver2\Assets\3.Scripts\Packet\Protocol"
XCOPY /Y Struct.cs "C:\Users\User\Documents\GitHub\SunNight_Ver2\Assets\3.Scripts\Packet\Protocol"
XCOPY /Y Protocol.cs "C:\Users\User\Documents\GitHub\SunNight_Ver2\Assets\3.Scripts\Packet\Protocol"

DEL /Q /F *.pb.h
DEL /Q /F *.pb.cc
DEL /Q /F *.h

DEL /Q /F *.cs

PAUSE