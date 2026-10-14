# Lab 8 — Part D Pseudocode Analysis

## D1 — Search and scan pseudocode

PROCEDURE FindAndCountActive(sortedIds, isActive, count, targetId)
    first = 0
    last = count - 1
    found = false

    WHILE first <= last AND found is false
        middle = (first + last) / 2

        IF sortedIds[middle] = targetId
            found = true
        ELSE IF sortedIds[middle] < targetId
            first = middle + 1
        ELSE
            last = middle - 1
        END IF
    END WHILE

    activeCount = 0
    FOR index = 0 TO count - 1
        IF isActive[index] is true
            activeCount = activeCount + 1
        END IF
    END FOR

    RETURN found, activeCount
END PROCEDURE

**Question:** 
### Explica el crecimiento de la sección de búsqueda y el de la sección que cuenta actividades. Luego clasifica el procedimiento completo. ¿Por qué no se multiplican automáticamente los costos de ambas secciones?


**Answer:**
## In the binary search, each iteration reduct the range to the middle, therefore it grows like 0(log n)
## The active count of the 'FOR' goes thru the 'n' elements one time, therefore it grows like O(n).
## The complete process: O(log n) + O(n) = O(n), because of the domain of lineal term.
## It doesn't multiply, because the costs only multiply when there are cicles added. Here the sections goes after the other, then it only add


## D2 — Potential-conflict pseudocode

PROCEDURE CountPotentialConflicts(startTimes, count)
    conflictCount = 0

    FOR first = 0 TO count - 1
        second = first + 1

        WHILE second < count
            IF startTimes[first] = startTimes[second]
                conflictCount = conflictCount + 1
            END IF

            second = second + 1
        END WHILE
    END FOR

    RETURN conflictCount
END PROCEDURE

**Question:**
### Explica por qué second comienza en first + 1, qué acción se cuenta como operación representativa y cuál es el orden de crecimiento en el caso de más trabajo. Apoya tu respuesta con lo que ocurriría al duplicar count.

**Answer:**
## The second one starts in "first + 1", to not compare a element with itself to not repeat pairs. The operation represent the comparison 'startsTimes[first] = startTimes[second].The order of growing(worst escenario): n(n - 1)/2 comparisons, basicily 0(n^2). When it comes to duplicate the count, they multiply by four. Example: n = 100 there is 4,950 comparison and with n = 200 are 19,900. 