
# 定义变量和引用变量
set(var "World!")
message("Hello ${var}")

# 定义列表和添加元素
set(stooges "Moe;Larry")
list(APPEND stooges "Curly")
message("Stooges contains: ${stooges}")

# 遍历列表
foreach(stooge IN LISTS stooges)
    message("Hello, ${stooge}")
endforeach()

# 宏
macro(MyMacro MacroArgument)
    message("${MacroArgument}\n\t\tFrom Macro")
endmacro()

# 函数
function(MyFunc FuncArgument)
    MyMacro("${FuncArgument}\n\tFrom Function")
endfunction()

MyFunc("From TopLevel")

# 用宏实现append
macro(MacroAppend ListVar Value)
    # ListVar像是二级指针，${}像是解引用
    set(${ListVar} "${${ListVar}};${Value}")
endmacro()

# 用函数实现append
function(FuncAppend ListVar Value)
    # 解引用形参${ListVar}值为字符串 "Letters"
    MacroAppend(${ListVar} ${Value})
    set(${ListVar} "${${ListVar}}" PARENT_SCOPE)
endfunction()

set(Letters "Alpha;Beta")
# 传参时字符串"Letters"传递给形参
FuncAppend(Letters "Gamma")
message("Letters contain: ${Letters}")

function(FilterFoo OutVar)
    foreach(item IN LISTS ARGN)
        if(item MATCHES Foo)
            list(APPEND ${OutVar} ${item})
        endif()
    endforeach()

    set(${OutVar} ${${OutVar}} PARENT_SCOPE)
endfunction()
