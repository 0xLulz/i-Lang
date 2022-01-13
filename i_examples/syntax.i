// Comment 
/*
    Multi Line Comment
*/

@insert Net // Looks thru iLang Lib directory for file name or directory called Net Or Net.h/net.h
@Insert Net.Http // Looks thru the directory called 'Net' and file name called http.h
@Insert "@i_root/net" // Same thing as the first line
@Insert "new.i" // File in the same directory
@Insert "../new.i" // Looks thru the directory before the current path

fnc main(argc{int}. argv{str}) {
    print("hello", NLINE);
};

// Normal/Private Function
fnc test() {
    print("This is a normal function. Private function");
    var test_if{str} = if(lang == i) {
        return 0;
    } else if(ilang == C) {
        return 0;
    };
};

fnc[str] test() {
    var message[str] = "This is a string return function";
    return message;
};

fnc{str} test(name{str}) {
    return "This is a string return function with string arguments (${name})";
};