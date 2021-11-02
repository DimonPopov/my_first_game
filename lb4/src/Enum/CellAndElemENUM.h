#pragma once

namespace CellTypes{
    enum CellState{
        OPEN, START, EXIT, CLOSE, OBJ1, OBJ2, OBJ3, MAX
    };
}

namespace Elements{
    enum DisposableObject{
        COINT, Obj2, Obj3
    };
}

namespace PlayerOrEnemy{
    enum PlayerVsEnemy{
        IamPLAYER, IamENEMY
    };
}