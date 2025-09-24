export interface ReelState {
    currentSymbol: number;
    isSpinning: boolean;
    stopDelay: number;
}

export interface ScoreNotification {
    id: number;
    points: number;
    x: number;
    y: number;
    timestamp: number;
}

export interface WindowDimensions {
    width: number;
    height: number;
}

export interface GameState {
    score: number;
    bestScore: number;
    spinsRemaining: number;
    isSpinning: boolean;
    showConfetti: boolean;
}