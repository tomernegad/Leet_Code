//Site that i use https://www.tutorialspoint.com/c_standard_library/c_function_memmove.htm.
//
//int compare(const void* a, const void* b)
//{
//    return *(char*)a - *(char*)b;
//}
//
//// Function to find the lexicographically smallest rotation of the string
//char* findSmallestRotation(char* s)
//{
//    int len = strlen(s);
//    char* smallestRotation = (char*)malloc((len + 1) * sizeof(char));
//    strcpy(smallestRotation, s);
//
//    // Rotate the string and update the smallest rotation (Arr smallestRotation)
//    for (int i = 0; i < len; i++)
//    {
//        char temp = s[0];
//        memmove(s, s + 1, len - 1);//Copy from one array to another. https://www.tutorialspoint.com/c_standard_library/c_function_memmove.htm.
//        // We make here the rotation to the left.
//        s[len - 1] = temp; // add our first char to end.
//        if (strcmp(s, smallestRotation) < 0) // we check arr s is smallr than smallestRotation if true we will copy s to smallestRotation.
//            strcpy(smallestRotation, s);
//    }
//
//    return smallestRotation;
//}
//
//char* orderlyQueue(char* s, int k)
//{
//    int len = strlen(s);
//    char* result = (char*)malloc((len + 1) * sizeof(char));
//
//    if (k == 1)
//    {
//        // Find the lexicographically smallest rotation of the string because we only can move the first char to end each time.
//        return findSmallestRotation(s);
//    }
//    else
//    {
//        // Sort the string directly
//        strcpy(result, s);
//        qsort(result, len, sizeof(char), compare);
//        return result;
//    }
//}