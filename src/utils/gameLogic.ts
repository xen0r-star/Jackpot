import { WINNING_COMBINATIONS } from '../constants';


export const calculateWinPoints = (symbols: string[]): { points: number; extraSpins: number } => {
    let points = 0;
    let extraSpins = 0;



    const hasAllSymbols = (requiredSymbols: string[]) => 
        requiredSymbols.every(symbol => symbols.includes(symbol));
    
    const isTriple = (symbol: string) =>
        symbols[0] === symbol && symbols[1] === symbol && symbols[2] === symbol;

    const isTripleFromList = (targetSymbols: string[]) =>
        symbols[0] === symbols[1] && symbols[1] === symbols[2] && 
        targetSymbols.includes(symbols[0]);


    
    // Triple 7
    if (isTriple('7')) {
        points = WINNING_COMBINATIONS.TRIPLE_SEVEN.points;
    }

    // Premium Mix
    else if (hasAllSymbols(WINNING_COMBINATIONS.PREMIUM_MIX.symbols) || 
             isTripleFromList(WINNING_COMBINATIONS.PREMIUM_MIX.symbols)) {
        points = WINNING_COMBINATIONS.PREMIUM_MIX.points;
    }

    // Fruit Mix
    else if (hasAllSymbols(WINNING_COMBINATIONS.FRUIT_MIX.symbols) || 
             isTripleFromList(WINNING_COMBINATIONS.FRUIT_MIX.symbols)) {
        points = WINNING_COMBINATIONS.FRUIT_MIX.points;
    }

    // Citrus Mix
    else if (hasAllSymbols(WINNING_COMBINATIONS.CITRUS_MIX.symbols) || 
             isTripleFromList(WINNING_COMBINATIONS.CITRUS_MIX.symbols)) {
        points = WINNING_COMBINATIONS.CITRUS_MIX.points;
    }

    // Diamonds
    else {
        const diamondCount = symbols.filter(s => s === WINNING_COMBINATIONS.DIAMOND.symbol).length;
        if (diamondCount > 0) {
            points = diamondCount * WINNING_COMBINATIONS.DIAMOND.pointsPerSymbol;
        }
    }

    // Clover
    const cloverCount = symbols.filter(s => s === WINNING_COMBINATIONS.CLOVER.symbol).length;
    if (cloverCount > 0) {
        extraSpins = cloverCount * WINNING_COMBINATIONS.CLOVER.spinsPerSymbol;
    }

    return { points, extraSpins };
};