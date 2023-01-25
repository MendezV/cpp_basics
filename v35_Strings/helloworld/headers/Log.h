// #pragma once //only include once, header guard
             // prevents including the same header file multiple times
             // into a single translation unit
             // avoids duplicate errors

// another way to put a header guard (for teaching and legacy)
#ifndef _LOG_H
#define _LOG_H

void Log(const char* message);
void InitLog();

#endif