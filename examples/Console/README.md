
---
## SioChatDemo setup

### Updates after Fork
- Updated to use Visual Studio 2017
- Using boost 1.69.0
- Updated **rapidjson** submodule to 
- Updated **websockets** submodule to 


### Steps to run the application,
- `git clone --recurse-submodules  https://github.com/pampas93/socket.io-client-cpp.git`
  - Cloning the socket.io-client-cpp repo along with the submodules (rapidjson and websockets)
- Download and build **boost** 
  - Built using boost 1.69.0 [Download link](https://www.boost.org/users/history/version_1_69_0.html)
  - Open cmd in the uncompressed directory,  run `bootstrap.bat`
  - Then, run `.\b2` to build boost
- Open SioChatDemo.sln in VS 2017 and link boost to the `SioChatDemo.vcxproj`
  - Right click on SioChatDemo project > Properties
  - C++ > General > Additional Include directories
  - Include boost_1_69_0 directory
  

---
Out-dated readme (from main repo)
---
#SioChatDemo setup
This Demo is create with `Visual Studio 2012 Update 4` , It is a simple console app, connect to official [socket.io chatroom example](https://github.com/Automattic/socket.io/tree/master/examples/chat) as a chat client.

You can choose a nickname, send/receive message in the chat room, and see join/left information as well.
##boost for windows
Please download boost package from [boost.org](www.boost.org), and unpack to `boost` folder.
Please make sure there's no redundent folder levels under it (by check if `bootstrap.bat` is directly under `boost` folder).

cd to `boost` folder, and run `bootstrap.bat`

Then run:

 ```shell
 bjam stage --toolset=msvc --with-system --with-date_time --with-random --stagedir="release" link=static runtime-link=shared threading=multi release
 bjam stage --toolset=msvc --with-system --with-date_time --with-random --stagedir="debug" link=static runtime-link=shared threading=multi debug
 ```
After done this, use Visual studio command line tool, go to `boost\release` folder, run

```shell
lib.exe /OUT:boost.lib *
```

And do then same thing in `boost\debug` folder.

then you can open the VS project `SioChatDemo.sln` to build and run.

##Visual studio version
Microsoft start to support c++11 after `Visual studio 2012 Update 4`. Please make sure you're using up-to-date version.
