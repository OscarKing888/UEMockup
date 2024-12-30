# UEMockup
UE mockup project - UE5.5

* 这是一个用于实验UE各种功能的工程
* 编译Server需要用源代码版本的引擎，通过修改_EngineDir.bat中的引擎路径再调用_GenerateProjectFilesGameVSCode.bat即可生成VS Code的workspace
* VS Code编译的结果可用_VSCode_StartDS.bat、_VSCode_StartGame.bat（默认双开）、_VSCode_StartGameStandalone.bat
* 注意：VS Code与 VS编译的是不一样的配置
* 注意：VS Code下编译带UEMockup开头的配置是编译成EXE，如果是UnrealEditor开头的是编译成DLL
* 注意：单独运行DS和Game需要先在Editor下Cook好对应版本的数据
* Plugins\MockupLifecycle\Doc\LifeCycleLog.xlsx有相关实验数据

# PyUtils(Python工具)
* extract_virtual_fun.bat可将传入的UE的.h类中所有的virtual函数提取出来 进行重载并实现为带LOG_FUN()的形式，方便进行快速实现实验类，如：
```c++
//.h
virtual void FinishRestartPlayer(AController* NewPlayer, const FRotator& StartRotation) override;

//.cpp
void AGameModeBase::FinishRestartPlayer(AController* NewPlayer, const FRotator& StartRotation)
{
    Super::FinishRestartPlayer(NewPlayer, StartRotation);
    LOG_FUN();
}
```
