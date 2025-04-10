//---------------------
psa[0][0] = a[0][0];
 
    // Filling first row and first column
    for (int i = 1; i < C; i++)
        psa[0][i] = psa[0][i - 1] + a[0][i];
    for (int i = 1; i < R; i++)
        psa[i][0] = psa[i - 1][0] + a[i][0];
 
    // updating the values in the cells
    // as per the general formula
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++)
 
            // values in the cells of new
            // array are updated
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1]
                        - psa[i - 1][j - 1] + a[i][j];
    }
//---------------------