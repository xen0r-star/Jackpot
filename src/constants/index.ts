export const SYMBOLS = [
    '7',
    'Banane',
    'Bar',
    'Cerise',
    'Citron',
    'Coeur',
    'Diament',
    'Dollar',
    'Orange',
    'Pasteque',
    'Pomme',
    'Prune',
    'Trefle'
] as const;

export const GAME_CONFIG = {
    INITIAL_SPINS: 100,
    SPIN_ANIMATION_DURATION: 2000,
    SPIN_STAGGER_DELAY: 500,
    REEL_ANIMATION_SPEED: 200,
    CONFETTI_DURATION: 3000,
    SCORE_NOTIFICATION_DURATION: 2500,
    CONFETTI_PIECES: 150,
};

export const WINNING_COMBINATIONS = {
    TRIPLE_SEVEN: { symbols: ['7', '7', '7'] as string[], points: 2500 },
    PREMIUM_MIX: { symbols: ['7', 'Dollar', 'Bar'] as string[], points: 1000 },
    FRUIT_MIX: { symbols: ['Pomme', 'Cerise', 'Pasteque'] as string[], points: 500 },
    CITRUS_MIX: { symbols: ['Citron', 'Orange', 'Banane'] as string[], points: 100 },
    DIAMOND: { symbol: 'Diament' as string, pointsPerSymbol: 50 },
    CLOVER: { symbol: 'Trefle' as string, spinsPerSymbol: 1 },
};

export const THEME_COLORS = {
    PRIMARY: '#B62345',
    SECONDARY: '#FFCD1E',
    BACKGROUND_DARK: '#0B1123',
    BACKGROUND_LIGHT: '#1a1a2e',
    TEXT_LIGHT: '#ffffffe6',
    SUCCESS: '#4ade80',
} as const;