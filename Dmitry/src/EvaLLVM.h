#ifndef EvaLLVM_h
#define EvaLLVM_h

#include <string>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
class EvaLLVM {
    public:
    EvaLLVM() {moduleInit();}

    void exec(const std::string& program) {
        compile()
        module->print(llvm::outs(),nullptr);
        saveModuleToFile("./out.ll");
    }

    private:

    void compile(){
        fn = createFunction("main", );
        auto result = gen();

        auto i32result = builder->CreateIntCast(result, builder->getInt32Ty(),true);
        builder->CreateRet(i32result);

    }

    llvm::Value* gen() {
        return builder->getInt32(42);
    }

    llvm::Function* createFunction (const std::string& fnName, llvm::FunctionType& fnType){}

    void saveModuleToFile(const std::string& fileName) {
        std::error_code errorCode;
        llvm::raw_fd_ostream outLL(fileName, errorCode);
        module->print(outLL, nullptr);
    }
    void moduleInit() {
        ctx = std::make_unique<llvm::LLVMContext>();
        module = std::make_unique<llvm::Module>("EvaLLVM",*ctx);
        builder = std::make_unique<llvm::IRBuilder<>>(*ctx);
    }
    std::unique_ptr<llvm::LLVMContext> ctx;

    std::unique_ptr<llvm::Module> module;

    std::unique_ptr<llvm::IRBuilder<>> builder;
};

#endif
