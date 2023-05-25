// SHUB TIMEWASTING ENTERPRISE presents
// a SHUB TIMEWASTING ENTERPRISE production
// a MONTE SHUB film
// 
// "Title Sequence 2"
// 
// 
// Cast
// Lightning Bolt 1: Monte Shub
// Lightning Bolt 2: Monte Shub
// Lightning Bolt 3: Monte Shub
// Lightning Bolt 4: Monte Shub
// DictionaryII Text: Monte Shub
// Revenge Text: Monte Shub
// 
// Casting Director: Monte Shub
// Costume Designer: Monte Shub
// Associate Producer: Monte Shub
// Editor: Monte Shub
// Production Designer: Monte Shub
// Director of Photography: Monte Shub
// Executive Producer: Monte Shub
// Producer: Monte Shub
// Writer: Monte Shub
// Director: Monte Shub

// title.cpp file
//  
// Monte Shub - 1/04/2023
//
// Function: title()
// input: None
// output: None
// description: Plays a visual sequence, causing user to experience emotions they didn't know they had, while simultaneously reminding them of a simpler time.
// functions required: <iostream>, <string>, <fstream>, <stdlib.h>, <chrono>, <thread>, <windows.h>, "slowtext.h"




#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>     
#include <windows.h>
#include <chrono>       
#include <thread>       
#include "title.h"
#include "SlowText.h"
#include "OST.h"
using namespace std;
int Sound;
void title(bool sound) { // Yeah... I felt like I had to one-up the last time I did this...
    if (sound) {
        Sound = 1;
    }
    else {
        Sound = 0;
    }
    OST(0, 0);
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    //below 4 lines are essentially groups of coordinates to 'animate' the titles
    const int NEWROW[217] = { 0,0,0,0,0,0,0,6,5,4,3,2,1,0,7,6,5,4,3,2,1,8,7,6,5,4,3,2,9,8,7,6,5,4,3,10,9,8,7,6,5,4,11,10,9,8,7,6,5,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,13,12,11,10,9,8,7,14,13,12,11,10,9,8,15,14,13,12,11,10,9,16,15,14,13,12,11,10,17,16,15,14,13,12,11,18,17,16,15,14,13,12 };
    const int NEWCOL[217] = { 0,0,0,0,0,0,0,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,1,2,3,4,5,6,7,2,3,4,5,6,7,8,3,4,5,6,7,8,9,4,5,6,7,8,9,10,5,6,7,8,9,10,11,6,7,8,9,10,11,12,7,8,9,10,11,12,13,8,9,10,11,12,13,14,9,10,11,12,13,14,15,10,11,12,13,14,15,16,11,12,13,14,15,16,17,12,13,14,15,16,17,18,13,14,15,16,17,18,19,14,15,16,17,18,19,20,15,16,17,18,19,20,21,16,17,18,19,20,21,22,17,18,19,20,21,22,23,17,18,19,20,21,22,23,17,18,19,20,21,22,23,17,18,19,20,21,22,23,17,18,19,20,21,22,23,17,18,19,20,21,22,23,17,18,19,20,21,22,23 };
    const int FROW[217] = { 6,5,4,3,2,1,0,7,6,5,4,3,2,1,8,7,6,5,4,3,2,9,8,7,6,5,4,3,10,9,8,7,6,5,4,11,10,9,8,7,6,5,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,12,11,10,9,8,7,6,13,12,11,10,9,8,7,14,13,12,11,10,9,8,15,14,13,12,11,10,9,16,15,14,13,12,11,10,17,16,15,14,13,12,11,18,17,16,15,14,13,12,18,18,18,18,18,18,18 };
    const int FCOL[217] = { 0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,1,2,3,4,5,6,7,2,3,4,5,6,7,8,3,4,5,6,7,8,9,4,5,6,7,8,9,10,5,6,7,8,9,10,11,6,7,8,9,10,11,12,7,8,9,10,11,12,13,8,9,10,11,12,13,14,9,10,11,12,13,14,15,10,11,12,13,14,15,16,11,12,13,14,15,16,17,12,13,14,15,16,17,18,13,14,15,16,17,18,19,14,15,16,17,18,19,20,15,16,17,18,19,20,21,16,17,18,19,20,21,22,17,18,19,20,21,22,23,17,18,19,20,21,22,23,17,18,19,20,21,22,23,17,18,19,20,21,22,23,17,18,19,20,21,22,23,17,18,19,20,21,22,23,17,18,19,20,21,22,23,23,23,23,23,23,23,23 };
    const string clearText[16][1] = { {R"(     )"},{R"(     )"},{R"(     )"},{R"(     )"},{R"(     )"},{R"(     )"},{R"(     )"},{R"(     )"},{R"(     )"},{R"(     )"},{R"(     )"},{R"(     )"},{R"(     )"},{R"(     )"},{R"(     )"} };
    // ASCII strings for the titles
    const string tagLine[7][24] = { {R"(  :::)",R"(:::::)",R"(::: :)",R"(::   )",R"( ::: )",R"(:::::)",R"(:::::)",R"(     )",R"(:::::)",R"(:::: )",R"( ::::)",R"(:::::)",R"(: :::)",R"(     )",R"(::: :)",R"(:::::)",R"(:::: )",R"(:::: )",R"(   ::)",R"(:  ::)",R"(:::::)",R"(:  ::)",R"(:::::)",R"(::: )"},
                             {R"(     )",R"(:+:  )",R"(   :+)",R"(:    )",R"(:+: :)",R"(+:   )",R"(     )",R"(    :)",R"(+:   )",R"( :+: )",R"(:+:  )",R"(     )",R"( :+: )",R"(    :)",R"(+: :+)",R"(:    )",R"(    :)",R"(+:+: )",R"(  :+:)",R"( :+: )",R"(   :+)",R"(: :+:)",R"(     )",R"(    )"},
                             {R"(    +)",R"(:+   )",R"(  +:+)",R"(    +)",R"(:+ +:)",R"(+    )",R"(     )",R"(   +:)",R"(+    )",R"(+:+ +)",R"(:+   )",R"(     )",R"(+:+  )",R"(   +:)",R"(+ +:+)",R"(     )",R"(   :+)",R"(:+:+ )",R"( +:+ )",R"(+:+  )",R"(     )",R"( +:+ )",R"(     )",R"(    )"},
                             {R"(   +#)",R"(+    )",R"( +#++)",R"(:++#+)",R"(+ +#+)",R"(+:++#)",R"(     )",R"(  +#+)",R"(+:++#)",R"(:  +#)",R"(++:++)",R"(#   +)",R"(#+   )",R"(  +:+)",R"( +#++)",R"(:++# )",R"(  +#+)",R"( +:+ )",R"(+#+ :)",R"(#:   )",R"(     )",R"(+#++:)",R"(++#  )",R"(    )"},
                             {R"(  +#+)",R"(     )",R"(+#+  )",R"(  +#+)",R"( +#+ )",R"(     )",R"(     )",R"( +#+ )",R"(   +#)",R"(+ +#+)",R"(     )",R"(    +)",R"(#+   )",R"(+#+  )",R"(+#+  )",R"(     )",R"( +#+ )",R"( +#+#)",R"(+# +#)",R"(+   +)",R"(#+# +)",R"(#+   )",R"(     )",R"(    )"},
                             {R"( #+# )",R"(    #)",R"(+#   )",R"( #+# )",R"(#+#  )",R"(     )",R"(     )",R"(#+#  )",R"(  #+#)",R"( #+# )",R"(     )",R"(    #)",R"(+#+#+)",R"(#   #)",R"(+#   )",R"(     )",R"(#+#  )",R"( #+#+)",R"(# #+#)",R"(    #)",R"(+# #+)",R"(#    )",R"(     )",R"(    )"},
                             {R"(###  )",R"(   ##)",R"(#    )",R"(### #)",R"(#####)",R"(#### )",R"(    #)",R"(##   )",R"( ### )",R"(#####)",R"(#####)",R"(     )",R"(###  )",R"(   ##)",R"(#####)",R"(### #)",R"(##   )",R"( ####)",R"(  ###)",R"(#####)",R"(  ###)",R"(#####)",R"(##   )",R"(    )"} };
    const string dictFine[19][24] = { { R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )" },
                                { R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )" },
                                { R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )" },
                                { R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )" },
                                { R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )" },
                                { R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )" },
                                { R"(`7MM")",R"(""Yb.)",R"( `7MM)",R"(F' .g)",R"(8"""b)",R"(gd MM)",R"(P""MM)",R"(""YMM)",R"( `7MM)",R"(F' .g)",R"(8""8q)",R"(. `7M)",R"(N.   )",R"(`7MF')",R"(     )",R"(db   )",R"(   `7)",R"(MM""")",R"(Mq.`Y)",R"(MM'  )",R"( `MM')",R"(   `7)",R"(MMF'`)",R"(7MMF')" },
                                { R"(  MM )",R"(   `Y)",R"(b. MM)",R"( .dP')",R"(     )",R"(`M P')",R"(   MM)",R"(   `7)",R"(   MM)",R"( .dP')",R"(    `)",R"(YM. M)",R"(MN.  )",R"(  M  )",R"(    ;)",R"(MM:  )",R"(     )",R"(MM   )",R"(`MM. )",R"(VMA  )",R"( ,V  )",R"(     )",R"(MM   )",R"( MM  )" },
                                { R"(  MM )",R"(    `)",R"(Mb MM)",R"( dM' )",R"(     )",R"( `   )",R"(   MM)",R"(     )",R"(   MM)",R"( dM' )",R"(     )",R"(`MM M)",R"( YMb )",R"(  M  )",R"(   ,V)",R"(^MM. )",R"(     )",R"(MM   )",R"(,M9  )",R"( VMA )",R"(,V   )",R"(     )",R"(MM   )",R"( MM  )" },
                                { R"(  MM )",R"(     )",R"(MM MM)",R"( MM  )",R"(     )",R"(     )",R"(   MM)",R"(     )",R"(   MM)",R"( MM  )",R"(     )",R"( MM M)",R"(  `MN)",R"(. M  )",R"(  ,M )",R"( `MM )",R"(     )",R"(MMmmd)",R"(M9   )",R"(  VMM)",R"(P    )",R"(     )",R"(MM   )",R"( MM  )" },
                                { R"(  MM )",R"(    ,)",R"(MP MM)",R"( MM. )",R"(     )",R"(     )",R"(   MM)",R"(     )",R"(   MM)",R"( MM. )",R"(     )",R"(,MP M)",R"(   `M)",R"(M.M  )",R"(  Abm)",R"(mmqMA)",R"(     )",R"(MM  Y)",R"(M.   )",R"(   MM)",R"(     )",R"(     )",R"(MM   )",R"( MM  )" },
                                { R"(  MM )",R"(   ,d)",R"(P' MM)",R"( `Mb.)",R"(     )",R"(,'   )",R"(   MM)",R"(     )",R"(   MM)",R"( `Mb.)",R"(    ,)",R"(dP' M)",R"(     )",R"(YMM  )",R"( A'  )",R"(   VM)",R"(L    )",R"(MM   )",R"(`Mb. )",R"(   MM)",R"(     )",R"(     )",R"(MM   )",R"( MM  )" },
                                { R"(.JMMm)",R"(mmdP')",R"( .JMM)",R"(L. `")",R"(bmmmd)",R"('    )",R"( .JMM)",R"(L.   )",R"( .JMM)",R"(L. `")",R"(bmmd")",R"(' .JM)",R"(L.   )",R"( YM .)",R"(AMA. )",R"(  .AM)",R"(MA..J)",R"(MML. )",R"(.JMM.)",R"( .JMM)",R"(L.   )",R"(   .J)",R"(MML..)",R"(JMML.)" },
                                { R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )" },
                                { R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )" },
                                { R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )" },
                                { R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )" },
                                { R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )" },
                                { R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )",R"(     )" } };
    const string starwipe[19] = { " "," "," "," "," "," ", "/////","/////","/////","/////","/////","/////","/////"," "," "," "," "," "," " };
    const int textRow = 8;
    const int textCol = 0;
    const int flashTime = 30; // timing modifier 
    const int LightSpeed = 40; //timing modifier
    const int textpause = 600; //timing modifier for the after the text has 'scrolled'
    const  int textSpeed = 100; //time between characters print
    const  int dotSpeed = 300; // same as above, but larger for more ominous '...'s
    const  int textheight = 15; // text high
    const int textIndent = 45; // text indent
    //below are the ASCII strings for the lightning bolts. keep it minimised for easier navigation
    const string bolt[6][22] = { { R"(                                         ]@    "%Ngg,,	)",
R"(                                          ]L          *N@wg,)",
R"(                                         ]g               "M@)",
R"(                                           %                ]@)",
R"(                                            ]b                "Ng,,,)",
R"(                                              @                 "@""`",)",
R"(                                              ]@                 @P    "*" mg,)",
R"(                                                *N,             ,@)",
R"(                                                  "@,            %,)",
R"(                                                    "**%g         "*N,)",
R"(                                                        %L           '*g   ,gg,,,)",
R"(                                                         g             'MM"    "%)",
R"(                                                         ]g                      %g,)",
R"(                                                          ]@,                      "@)",
R"(                                                         ,g@P%,                      "*,)",
R"(                                                         %     @)",
R"(                                                          y   ,P)",
R"(                                                         jL   %F)",
R"(                                                               *w,)",
R"(                                                                 ]b)",
R"(                                                                   *Nm,,,)",
R"(                                                                        *,)" },
{R"(                                                                                  ]U@*`              ])",
R"(                                                                             ,,gpK$P                ,@)",
R"(                                                            ,g, ,,     , ,w{^`   ,/                 [)",
R"(                                                        ,p@"      `***"```        @,               N)",
R"(                                                      ,2`                          ]b,            &)",
R"(                                     ,.%^""``"~%gp%N*"`                            *YR`          AF)",
R"(                                   gP                                              /`]K         ][)",
R"(                                   @                                               "  `          `)",
R"(                                   $F)",
R"(                              ,wg@C`)",
R"(                            ,@)",
R"(                       ,$***^)",
R"(                    @@R^)",
R"(                   ]CQ)",
R"(                     ]L)",
R"(                    ][)",
R"(                   ][)",
R"(                   ][)",
R"(                   ][)",
R"(                  g%)",
R"(                 ]B)",
R"(                 ][)"},
{R"(                                               ,g@P-                            )",
R"(                                              ]@M"                              )",
R"(                                             g"]g                               )",
R"(                                           ,@*  $-                              )",
R"(                                          yM    $C                              )",
R"(                                         ]F     @                               )",
R"(                                       gM*      %                               )",
R"(                                     g@'        @                               )",
R"(                                  >@"          ,@                               )",
R"(                                gM*            @-                               )",
R"(                               g'             @L                                )",
R"(                              ]F            ,@*                                 )",
R"(                         y,gN"`            gM                                   )",
R"(                     ,*"|*'            ;gmM-                                    )",
R"(                    +` >L              j@                                       )",
R"(                   L  |               ,@`                                       )",
R"(                      "              gF                                         )",
R"(                     '               ]                                          )",
R"(                                     ]L                                         )",
R"(                                     ]@                                         )",
R"(                                     "@                                         )",
R"(                                      $      					     )"},
{R"(                     ?*r*v;                  )g;gw, ,wwe$"   yC      `F "v             A ]  aC`)",
R"(                           ]L       ,     ,gF"    --    P    F       LL   t           **' 7L *w)",
R"(                             Ywgw*-"   w#*-             %    P        LL   *-              ]  ]g,g,       /^)",
R"(                              ]w     ,@                @    J         \|                    1 %]    `**?*-)",
R"(                         |   j`      $                #     $          ]]                    F ]C)",
R"(                         `\w4"  ,,rMC               yC     ]L          ] .                  *w ]J<)",
R"(                        ;F *Yww" ` '              ]*       F           ,L]                    J L V)",
R"(                       =          *            P%f-       ]           A7]-                    '%*~.,r!)",
R"(                                              F [         $         ,F  * g                     ]v,)",
R"(                                             A  C         ]        g=    rC%                   ,hL   '^"')",
R"(                                          )r7   ]        /*              L}]OKg               'L         })",
R"(                                     ;/C`=     ,F     y4*`             ,*gL  *c|               i          `)",
R"(                                 ,r*-       >""     wC                ,M"-    -*C              "\          .)",
R"(                          ..,,wwP          [      J[                  #j-`      "*w              y         `)",
R"(                           wC   -         /      A ]                 ;ryC          "$7w)",
R"(                         ,C    ,          L    ,F  ]                 L.=            ]   ]"V)",
R"(                       ;r-                `  x*    $                 ]y\             ]     ]PVw,)",
R"(                     /*                    /"     ]L                ]k ]/;            *%w  "w)",
R"(                   /*                   ,Lr-     /"                   VQNrC              [   -"""c)",
R"(                ,`                    r>       $*                      ^%@/y             e*w      7~)",
R"(               '                       '      /\                         $ C             | v)",
R"(                                           '` $                        ,^;C                 **L)" },
{R"(                                  ]@)",
R"(                                   ]$)",
R"(                                    %,)",
R"(                                    Ng)",
R"(                                    @h)",
R"(                                    ,%)",
R"(                                    ]$)",
R"(                                      ]k)",
R"(                                      ][,)",
R"(                                        $)",
R"(                                          A)",
R"(                                          K%)",
R"(                                          h)",
R"(                                           @)",
R"(                                           Rh,)",
R"(                                             *)g)",
R"(                                             ]$)",
R"(                                                %[)",
R"(                                               ]@@y)",
R"(                                                ""^%%)",
R"(                                                      )",
R"(                                                       )"} ,
{ R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                      )",
R"(                                                       )" } };


    SetConsoleTextAttribute(hConsole, 14);//lightning bolt 1
    for (int b = 0; b < 22; b++) {
        cout << bolt[0][b] << endl;
        this_thread::sleep_for(chrono::milliseconds(LightSpeed));
    }
    OST(15, Sound);
    this_thread::sleep_for(chrono::milliseconds(flashTime * 2));//lightning flash 1 START
    std::system("cls");
    std::system("Color F7");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("Color 01");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("Color F7");
    this_thread::sleep_for(chrono::milliseconds(flashTime)); //lightning flash 1 END
    std::system("cls");
    std::system("Color 07");
    slowText("You survived it once", textheight, textIndent, textSpeed);
    slowText(".", textheight, textIndent + 20, dotSpeed);
    this_thread::sleep_for(chrono::milliseconds(textpause / 2));
    slowText("Barely", textheight + 2, textIndent, textSpeed);
    slowText("...", textheight + 2, textIndent + 6, dotSpeed);
    this_thread::sleep_for(chrono::milliseconds(textpause));
    std::system("cls");

    SetConsoleTextAttribute(hConsole, 14);//lightning bolt 2
    for (int b = 0; b < 22; b++) {
        cout << bolt[1][b] << endl;
        this_thread::sleep_for(chrono::milliseconds(LightSpeed));
    }
    OST(14, Sound);

    std::system("cls");//lightning flash 2 START
    std::system("Color F7");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("Color 01");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("Color F7");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("cls");//lightning flash 2 END

    std::system("Color 07");
    slowText("But the nightmare isn't over", textheight, textIndent, textSpeed);
    slowText("...", textheight, textIndent + 28, dotSpeed);
    this_thread::sleep_for(chrono::milliseconds(textpause));
    std::system("cls");



    SetConsoleTextAttribute(hConsole, 14);//lightning bolt 3
    for (int b = 0; b < 22; b++) {
        cout << bolt[2][b] << endl;
        this_thread::sleep_for(chrono::milliseconds(LightSpeed));

    }
    OST(13, Sound);

    std::system("cls");//lightning flash 3 START
    std::system("Color F7");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("Color 01");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("Color F7");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("cls");//lightning flash 3 END

    std::system("Color 07");
    slowText("It's back", textheight, textIndent, textSpeed);
    slowText("...", textheight, textIndent + 9
        , dotSpeed);
    slowText("Now it's angry", textheight + 2, textIndent, textSpeed);
    slowText("...", textheight + 2, textIndent + 14, dotSpeed);
    this_thread::sleep_for(chrono::milliseconds(textpause));
    std::system("cls");

    SetConsoleTextAttribute(hConsole, 14);//lightning bolt 4
    for (int b = 0; b < 22; b++) {
        cout << bolt[3][b] << endl;
        this_thread::sleep_for(chrono::milliseconds(LightSpeed));

    }
    OST(12, Sound);

    std::system("cls");//lightning flash 4 START
    std::system("Color F7");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("Color 01");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("Color F7");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("Color 01");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("Color F7");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("Color 01");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("Color F7");
    this_thread::sleep_for(chrono::milliseconds(flashTime));
    std::system("cls");//lightning flash 4 START
    std::system("Color 01");
    SetConsoleTextAttribute(hConsole, 14);//lightning bolt 5
    for (int b = 0; b < 21; b++) {
        cout << bolt[4][b] << endl;
        this_thread::sleep_for(chrono::milliseconds(LightSpeed));
    }
    //std::system("cls");
    OST(16, Sound);
    std::system("Color F7");
    this_thread::sleep_for(chrono::milliseconds(flashTime)); //final flash before title
    std::system("Color 06");
    for (int i = 0; i < 217; i++) {
        printf("\033[%d;%dH", textRow + NEWROW[i], textCol + NEWCOL[i] * 5);
        std::cout << dictFine[NEWROW[i]][NEWCOL[i]]; //print dictionary with no delay (yellow)
    }
    for (int k = 0; k < 2; k++) {

        for (int n = 0; n < 217; n++) {

            SetConsoleTextAttribute(hConsole, 8); //grey colour
            printf("\033[%d;%dH", textRow + FROW[n], textCol + FCOL[n] * 5);
            std::cout << starwipe[FROW[n]]; // wipe over the yellow 'dictionary' 

            SetConsoleTextAttribute(hConsole, 9);//blue
            printf("\033[%d;%dH", textRow + NEWROW[n], textCol + NEWCOL[n] * 5);
            std::cout << dictFine[NEWROW[n]][NEWCOL[n]];//print dictionary 'behind' the wipe

            if (n % 7 == 0) {
                this_thread::sleep_for(chrono::milliseconds(flashTime));
                if ((n / 14) < 14) {
                    printf("\033[%d;%dH", n / 14, 1);
                    cout << bolt[5][n / 14] << endl;
                }

            }
        }
    }
    //this next block allows the tagline to print from the centre going outward, both vertically and horizontally
    for (int c = 0; c < 2; c++) {
        int count = 0;
        for (int i = 12; i < 24; i++) {
            count += 2;
            for (int j = 3; j < 7; j++) {
                SetConsoleTextAttribute(hConsole, 12 - 8 * c);
                printf("\033[%d;%dH", textRow + 6 - j + 13, 2 + textCol + i * 5);
                std::cout << tagLine[6 - j][i];
                printf("\033[%d;%dH", textRow + 6 - j + 13, 2 + textCol + (i - count + 1) * 5);
                std::cout << tagLine[6 - j][i - count + 1];
                printf("\033[%d;%dH", textRow + j + 13, 2 + textCol + i * 5);
                std::cout << tagLine[j][i];
                printf("\033[%d;%dH", textRow + j + 13, 2 + textCol + (i - count + 1) * 5);
                std::cout << tagLine[j][i - count + 1];
                this_thread::sleep_for(chrono::milliseconds(1));
            }
        }
    }
    this_thread::sleep_for(chrono::milliseconds(textpause));
    //next block clears the screen by printing whitespace from the centre-> outwards
    for (int i = 12; i < 25; i++) {
        for (int j = 7; j < 16; j++) {
            printf("\033[%d;%dH", textRow + 20 - j, 1 + textCol + i * 5);
            std::cout << clearText[j][0];
            printf("\033[%d;%dH", textRow + 20 - j, 1 + textCol + (24 - i) * 5);
            std::cout << clearText[15 - j][0];
            printf("\033[%d;%dH", textRow + 20 - (15 - j), 1 + textCol + i * 5);
            std::cout << clearText[j][0];
            printf("\033[%d;%dH", textRow + 20 - (15 - j), 1 + textCol + (24 - i) * 5);
            std::cout << clearText[15 - j][0];

            this_thread::sleep_for(chrono::milliseconds(10));
        }
    }


    this_thread::sleep_for(chrono::milliseconds(300));// leaves you in awe for .3 seconds before opening the dictionary.

   
}
//*Takes a bow*




