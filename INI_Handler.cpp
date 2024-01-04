#pragma once
#include "Class_Handler.h"
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <iostream>

namespace INI {
	using namespace System;
    using namespace System::IO;
    using namespace msclr::interop;
    using namespace std;

	System::Void INI::INI_Handler::Game_INI_File(System::String^ ASA_Server_Path) {
		if (!Directory::Exists(ASA_Server_Path + "\\ShooterGame\\Saved\\Config\\WindowsServer") || !System::IO::File::Exists(ASA_Server_Path + "\\ShooterGame\\Saved\\Config\\WindowsServer\\Game.ini")) {
			Directory::CreateDirectory(ASA_Server_Path + "\\ShooterGame\\Saved\\Config\\WindowsServer");
			std::string convertedFolderPath = msclr::interop::marshal_as<std::string>(ASA_Server_Path);
			Create_INI_Game_File(convertedFolderPath);
		}
	}

    System::Void INI::INI_Handler::Create_INI_Game_File(const std::string& folder_path)
    {
        std::ofstream file(folder_path + "\\ShooterGame\\Saved\\Config\\WindowsServer\\Game.ini");
        if (file.is_open()) {            
			file << "[ServerSettings]" << std::endl;
			file << "ShowMapPlayerLocation = True" << std::endl;
			file << "AllowThirdPersonPlayer = True" << std::endl;
			file << "ServerCrosshair = True" << std::endl;
			file << "RCONPort = 27020" << std::endl;
			file << "TheMaxStructuresInRange = 10500" << std::endl;
			file << "StartTimeHour = 0.25" << std::endl;
			file << "OxygenSwimSpeedStatMultiplier = 1" << std::endl;
			file << "StructurePreventResourceRadiusMultiplier = 1" << std::endl;
			file << "TribeNameChangeCooldown = 15" << std::endl;
			file << "PlatformSaddleBuildAreaBoundsMultiplier = 1" << std::endl;
			file << "AlwaysAllowStructurePickup = True" << std::endl;
			file << "StructurePickupTimeAfterPlacement = 30" << std::endl;
			file << "StructurePickupHoldDuration = 0.5" << std::endl;
			file << "AllowHideDamageSourceFromLogs = True" << std::endl;
			file << "RaidDinoCharacterFoodDrainMultiplier = 1" << std::endl;
			file << "PvEDinoDecayPeriodMultiplier = 1" << std::endl;
			file << "KickIdlePlayersPeriod = 3600" << std::endl;
			file << "PerPlatformMaxStructuresMultiplier = 1" << std::endl;
			file << "AutoSavePeriodMinutes = 15" << std::endl;
			file << "MaxTamedDinos = 5000" << std::endl;
			file << "ItemStackSizeMultiplier = 1" << std::endl;
			file << "RCONServerGameLogBuffer = 600" << std::endl;
			file << "ImplantSuicideCD = 28800" << std::endl;
			file << "AllowHitMarkers = True" << std::endl;
			file << "RCONEnabled = false" << std::endl;
			file << "DifficultyOffset = 0.600000024" << std::endl;
			file << "PlayerDamageMultiplier = 2" << std::endl;
			file << "StructureResistanceMultiplier = 0.5" << std::endl;
			file << "XPMultiplier = 2" << std::endl;
			file << "TamingSpeedMultiplier = 3" << std::endl;
			file << "HarvestAmountMultiplier = 1.5" << std::endl;
			file << "PlayerCharacterWaterDrainMultiplier = 0.5" << std::endl;
			file << "PlayerCharacterFoodDrainMultiplier = 0.5" << std::endl;
			file << "DinoCharacterFoodDrainMultiplier = 0.5" << std::endl;
			file << "PlayerCharacterStaminaDrainMultiplier = 0.5" << std::endl;
			file << "DinoCharacterStaminaDrainMultiplier = 0.5" << std::endl;
			file << "PlayerCharacterHealthRecoveryMultiplier = 2" << std::endl;
			file << "DinoCharacterHealthRecoveryMultiplier = 2" << std::endl;
			file << "StartTimeOverride = False" << std::endl;
			file << "ListenServerTetherDistanceMultiplier = 1" << std::endl;
			file << "AllowRaidDinoFeeding = True" << std::endl;
			file << "GlobalVoiceChat = False" << std::endl;
			file << "ProximityChat = False" << std::endl;
			file << "NoTributeDownloads = False" << std::endl;
			file << "AlwaysNotifyPlayerLeft = False" << std::endl;
			file << "DontAlwaysNotifyPlayerJoined = False" << std::endl;
			file << "ServerHardcore = False" << std::endl;
			file << "ServerPVE = True" << std::endl;
			file << "ServerForceNoHUD = False" << std::endl;
			file << "EnablePvPGamma = True" << std::endl;
			file << "DisableStructureDecayPvE = True" << std::endl;
			file << "AllowFlyerCarryPvE = True" << std::endl;
			file << "OnlyAllowSpecifiedEngrams = False" << std::endl;
			file << "RandomSupplyCratePoints = False" << std::endl;
			file << "DisableWeatherFog = False" << std::endl;
			file << "PreventDownloadSurvivors = False" << std::endl;
			file << "PreventDownloadItems = False" << std::endl;
			file << "PreventDownloadDinos = False" << std::endl;
			file << "DisablePvEGamma = False" << std::endl;
			file << "DisableDinoDecayPvE = False" << std::endl;
			file << "AdminLogging = False" << std::endl;
			file << "AllowCaveBuildingPvE = True" << std::endl;
			file << "ForceAllowCaveFlyers = True" << std::endl;
			file << "PreventOfflinePvP = False" << std::endl;
			file << "PvPDinoDecay = False" << std::endl;
			file << "OverrideStructurePlatformPrevention = False" << std::endl;
			file << "AllowAnyoneBabyImprintCuddle = False" << std::endl;
			file << "DisableImprintDinoBuff = False" << std::endl;
			file << "ShowFloatingDamageText = True" << std::endl;
			file << "PreventDiseases = False" << std::endl;
			file << "NonPermanentDiseases = True" << std::endl;
			file << "EnableExtraStructurePreventionVolumes = False" << std::endl;
			file << "PreventTribeAlliances = False" << std::endl;
			file << "bAllowSpeedLeveling = False" << std::endl;
			file << "bAllowFlyerSpeedLeveling = False" << std::endl;
			file << "PreventOfflinePvPInterval = -0" << std::endl;
			file << "CraftingSkillBonusMultiplier = 1" << std::endl;
			file << "SupplyCrateLootQualityMultiplier = 1" << std::endl;
			file << "ActiveEvent =" << std::endl;
			file << "OverrideStartTime = False" << std::endl;
			file << "ActiveMods =" << std::endl;
			file << "ActiveMapMod = 0" << std::endl;
			file << "" << std::endl;
			file << "[ScalabilityGroups]" << std::endl;
			file << "sg.ResolutionQuality = 75" << std::endl;
			file << "sg.ViewDistanceQuality = 1" << std::endl;
			file << "sg.AntiAliasingQuality = 1" << std::endl;
			file << "sg.ShadowQuality = 2" << std::endl;
			file << "sg.GlobalIlluminationQuality = 3" << std::endl;
			file << "sg.ReflectionQuality = 3" << std::endl;
			file << "sg.PostProcessQuality = 1" << std::endl;
			file << "sg.TextureQuality = 2" << std::endl;
			file << "sg.EffectsQuality = 1" << std::endl;
			file << "sg.FoliageQuality = 2" << std::endl;
			file << "sg.ShadingQuality = 3" << std::endl;
			file << "" << std::endl;
			file << "[/Script/ShooterGame.ShooterGameUserSettings]" << std::endl;
			file << "AdvancedGraphicsQuality = 1" << std::endl;
			file << "MasterAudioVolume = 1.000000" << std::endl;
			file << "MusicAudioVolume = 0.800000" << std::endl;
			file << "SFXAudioVolume = 1.000000" << std::endl;
			file << "VoiceAudioVolume = 1.000000" << std::endl;
			file << "SoundUIAudioVolume = 1.000000" << std::endl;
			file << "CharacterAudioVolume = 1.000000" << std::endl;
			file << "StructureTooltipMaxSpeedMultiply = 0.000000" << std::endl;
			file << "UIScaling = 1.000000" << std::endl;
			file << "UIQuickbarScaling = 0.750000" << std::endl;
			file << "CameraShakeScale = 0.650000" << std::endl;
			file << "bFirstPersonRiding = False" << std::endl;
			file << "bThirdPersonPlayer = True" << std::endl;
			file << "bShowStatusNotificationMessages = True" << std::endl;
			file << "TrueSkyQuality = 0.270000" << std::endl;
			file << "FOVMultiplier = 1.000000" << std::endl;
			file << "GroundClutterDensity = 1.000000" << std::endl;
			file << "bFilmGrain = False" << std::endl;
			file << "bMotionBlur = True" << std::endl;
			file << "bUseGamepadSpeaker = True" << std::endl;
			file << "bUseDFAO = False" << std::endl;
			file << "bUseSSAO = True" << std::endl;
			file << "bShowChatBox = True" << std::endl;
			file << "bCameraViewBob = True" << std::endl;
			file << "bInvertLookY = False" << std::endl;
			file << "bFloatingNames = True" << std::endl;
			file << "bChatBubbles = True" << std::endl;
			file << "bHideServerInfo = False" << std::endl;
			file << "bJoinNotifications = False" << std::endl;
			file << "bDisableNameYourTamePopup = False" << std::endl;
			file << "MinimalFloatingNameSetting = False" << std::endl;
			file << "bCraftablesShowAllItems = False" << std::endl;
			file << "bLocalInventoryItemsShowAllItems = False" << std::endl;
			file << "bLocalInventoryCraftingShowAllItems = True" << std::endl;
			file << "bRemoteInventoryItemsShowAllItems = False" << std::endl;
			file << "bRemoteInventoryCraftingShowAllItems = False" << std::endl;
			file << "bRemoteInventoryShowEngrams = True" << std::endl;
			file << "bEnableLowLightEnhancement = True" << std::endl;
			file << "bEnableFluidInteraction = True" << std::endl;
			file << "bDisableHLOD = False" << std::endl;
			file << "LookLeftRightSensitivity = 1.000000" << std::endl;
			file << "LookUpDownSensitivity = 1.000000" << std::endl;
			file << "TPVCameraHorizontalOffsetFactor = 0.000000" << std::endl;
			file << "GraphicsQuality = 1" << std::endl;
			file << "ActiveLingeringWorldTiles = 10" << std::endl;
			file << "ClientNetQuality = 3" << std::endl;
			file << "TheGammaCorrection = 0.500000" << std::endl;
			file << "LastServerSearchType = 0" << std::endl;
			file << "LastServerSort = 2" << std::endl;
			file << "LastPVESearchType = -1" << std::endl;
			file << "LastDLCTypeSearchType = -1" << std::endl;
			file << "LastServerSortAsc = True" << std::endl;
			file << "LastAutoFavorite = True" << std::endl;
			file << "LastServerSearchHideFull = False" << std::endl;
			file << "LastServerSearchProtected = False" << std::endl;
			file << "LastPlatformSpecificServerSearch = False" << std::endl;
			file << "HideItemTextOverlay = True" << std::endl;
			file << "bForceShowItemNames = False" << std::endl;
			file << "bDistanceFieldShadowing = True" << std::endl;
			file << "bDisableShadows = False" << std::endl;
			file << "LODScalar = 1.000000" << std::endl;
			file << "bToggleToTalk = False" << std::endl;
			file << "HighQualityMaterials = True" << std::endl;
			file << "HighQualitySurfaces = True" << std::endl;
			file << "bTemperatureF = False" << std::endl;
			file << "bDisableTorporEffect = False" << std::endl;
			file << "bChatShowSteamName = False" << std::endl;
			file << "bChatShowTribeName = True" << std::endl;
			file << "bReverseTribeLogOrder = False" << std::endl;
			file << "EmoteKeyBind1 = 0" << std::endl;
			file << "EmoteKeyBind2 = 0" << std::endl;
			file << "bNoBloodEffects = False" << std::endl;
			file << "bLowQualityVFX = False" << std::endl;
			file << "bSpectatorManualFloatingNames = False" << std::endl;
			file << "bSuppressAdminIcon = False" << std::endl;
			file << "bUseSimpleDistanceMovement = False" << std::endl;
			file << "bHasSavedGame = False" << std::endl;
			file << "bDisableMeleeCameraSwingAnims = False" << std::endl;
			file << "bPreventInventoryOpeningSounds = False" << std::endl;
			file << "bPreventBiomeWalls = False" << std::endl;
			file << "bPreventHitMarkers = False" << std::endl;
			file << "bPreventCrosshair = False" << std::endl;
			file << "bPreventColorizedItemNames = False" << std::endl;
			file << "bHighQualityLODs = False" << std::endl;
			file << "bExtraLevelStreamingDistance = False" << std::endl;
			file << "bEnableColorGrading = False" << std::endl;
			file << "VSyncMode = 1" << std::endl;
			file << "DOFSettingInterpTime = 0.000000" << std::endl;
			file << "LastJoinedSessionPerCategory = \" \"" << std::endl;
			file << "LastJoinedSessionPerCategory = \" \"" << std::endl;
			file << "LastJoinedSessionPerCategory = \" \"" << std::endl;
			file << "LastJoinedSessionPerCategory = \" \"" << std::endl;
			file << "LastJoinedSessionPerCategory = \" \"" << std::endl;
			file << "LastJoinedSessionPerCategory = \" \"" << std::endl;
			file << "LastJoinedSessionPerCategory = \" \"" << std::endl;
			file << "LastJoinedSessionPerCategory = \" \"" << std::endl;
			file << "LastJoinedSessionPerCategory = \" \"" << std::endl;
			file << "LastSessionCategoryJoined = -1" << std::endl;
			file << "bDisableMenuTransitions = False" << std::endl;
			file << "bEnableInventoryItemTooltips = True" << std::endl;
			file << "bRemoteInventoryShowCraftables = False" << std::endl;
			file << "bNoTooltipDelay = False" << std::endl;
			file << "LocalItemSortType = 0" << std::endl;
			file << "LocalCraftingSortType = 0" << std::endl;
			file << "RemoteItemSortType = 0" << std::endl;
			file << "RemoteCraftingSortType = 0" << std::endl;
			file << "VersionMetaTag = 1" << std::endl;
			file << "ShowExplorerNoteSubtitles = False" << std::endl;
			file << "DisableMenuMusic = False" << std::endl;
			file << "DisableDefaultCharacterItems = False" << std::endl;
			file << "DisableLoadScreenMusic = False" << std::endl;
			file << "bRequestDefaultCharacterItemsOnce = False" << std::endl;
			file << "bHasSeenGen2Intro = False" << std::endl;
			file << "CinematicForNoteShouldReset = ()" << std::endl;
			file << "bHasSetupDifficultySP = False" << std::endl;
			file << "bHasSetupVisualSettings = False" << std::endl;
			file << "agreedToTerms = ()" << std::endl;
			file << "bHasRunAutoSettings = False" << std::endl;
			file << "bHideFloatingPlayerNames = False" << std::endl;
			file << "bHideGamepadItemSelectionModifier = False" << std::endl;
			file << "bToggleExtendedHUDInfo = False" << std::endl;
			file << "PlayActionWheelClickSound = True" << std::endl;
			file << "PlayHUDRolloverSound = True" << std::endl;
			file << "CompanionReactionVerbosity = 3" << std::endl;
			file << "EnableEnvironmentalReactions = True" << std::endl;
			file << "EnableRespawnReactions = True" << std::endl;
			file << "EnableDeathReactions = True" << std::endl;
			file << "EnableSayHelloReactions = True" << std::endl;
			file << "EnableEmoteReactions = True" << std::endl;
			file << "EnableMovementSounds = True" << std::endl;
			file << "DisableSubtitles = False" << std::endl;
			file << "bEnableASACamera = True" << std::endl;
			file << "ConsoleAccess = False" << std::endl;
			file << "CompanionSubtitleVerbosityLevel = 3" << std::endl;
			file << "CompanionIsHiddenState = False" << std::endl;
			file << "MaxAscensionLevel = 0" << std::endl;
			file << "bHostSessionHasBeenOpened = False" << std::endl;
			file << "bForceTPVCameraOffset = False" << std::endl;
			file << "bDisableTPVCameraInterpolation = False" << std::endl;
			file << "bEnableHDROutput = False" << std::endl;
			file << "HDRDisplayMinLuminance = -4.000000" << std::endl;
			file << "HDRDisplayMidLuminance = 20.000000" << std::endl;
			file << "HDRDisplayMaxLuminance = 1400.000000" << std::endl;
			file << "FoliageInteractionDistance = 1.000000" << std::endl;
			file << "FoliageInteractionDistanceLimit = 1.000000" << std::endl;
			file << "FoliageInteractionQuantityLimit = 1.000000" << std::endl;
			file << "bFPVClimbingGear = False" << std::endl;
			file << "bFPVGlidingGear = False" << std::endl;
			file << "bHasInitializedScreenPercentage = False" << std::endl;
			file << "CameraZoomPerDinoNameTag = ()" << std::endl;
			file << "CameraHeightPerDinoNameTag = ()" << std::endl;
			file << "PhotomodePresets_Camera = ()" << std::endl;
			file << "PhotomodePresets_Movement = ()" << std::endl;
			file << "PhotomodePresets_Splines = ()" << std::endl;
			file << "PhotomodePresets_PPs = ()" << std::endl;
			file << "PhotomodePresets_Targeting = ()" << std::endl;
			file << "PhotomodeLastUsedSettings = ()" << std::endl;
			file << "MaxLastDeathMark = 5" << std::endl;
			file << "bSaveLastDeathMark = True" << std::endl;
			file << "bShowPingsOnMap = True" << std::endl;
			file << "bShowDinosOnMap = True" << std::endl;
			file << "bShowWaypointsOnMap = True" << std::endl;
			file << "bShowPlayersOnMap = True" << std::endl;
			file << "bShowBedsOnMap = True" << std::endl;
			file << "AimAssistStrengthMultiplier = 1.000000" << std::endl;
			file << "bForceShowRadialWheelTexts = False" << std::endl;
			file << "bHideStructurePlacementCrosshair = False" << std::endl;
			file << "SavedMainMapZoom = 1.000000" << std::endl;
			file << "SavedOverlayMapZoom = 1.000000" << std::endl;
			file << "bMinimalUI = False" << std::endl;
			file << "FloatingTooltipStructureMode = DEFAULT" << std::endl;
			file << "FloatingTooltipDinoMode = DEFAULT" << std::endl;
			file << "FloatingTooltipDroppedItemsMode = DEFAULT" << std::endl;
			file << "FloatingTooltipPlayerMode = DEFAULT" << std::endl;
			file << "TopNotificationMode = DEFAULT" << std::endl;
			file << "ItemNotificationMode = MINIMAL" << std::endl;
			file << "bMinimapOverlayUseLowOpacity = False" << std::endl;
			file << "FilterTypeInventoryLocal = 9" << std::endl;
			file << "FilterTypeInventoryRemote = 9" << std::endl;
			file << "bUseGamepadAimAssist = RangeWeaponAlwaysOn" << std::endl;
			file << "Gamma1 = 2.200000" << std::endl;
			file << "Gamma2 = 3.000000" << std::endl;
			file << "bDisableBloom = False" << std::endl;
			file << "bDisableLightShafts = False" << std::endl;
			file << "bUseLowQualityLevelStreaming = True" << std::endl;
			file << "bUseDistanceFieldAmbientOcclusion = False" << std::endl;
			file << "bPreventItemCraftingSounds = False" << std::endl;
			file << "bHighQualityAnisotropicFiltering = False" << std::endl;
			file << "AmbientSoundVolume = 1.000000" << std::endl;
			file << "bUseOldThirdPersonCameraTrace = False" << std::endl;
			file << "bUseOldThirdPersonCameraOffset = False" << std::endl;
			file << "bShowedGenesisDLCBackground = False" << std::endl;
			file << "bShowedGenesis2DLCBackground = False" << std::endl;
			file << "bHasStartedTheGameOnce = False" << std::endl;
			file << "bViewedAnimatedSeriesTrailer = False" << std::endl;
			file << "bViewedARK2Trailer = False" << std::endl;
			file << "bShowRTSKeyBinds = True" << std::endl;
			file << "bHasCompletedGen2 = False" << std::endl;
			file << "bEnableFootstepDecals = True" << std::endl;
			file << "bEnableFootstepParticles = True" << std::endl;
			file << "bShowInfoButtons = True" << std::endl;
			file << "bDisablePaintings = False" << std::endl;
			file << "StopExplorerNoteAudioOnClose = False" << std::endl;
			file << "bVibration = True" << std::endl;
			file << "bUIVibration = False" << std::endl;
			file << "radialSelectionSpeed = 0.650000" << std::endl;
			file << "bDisableVirtualCursor = False" << std::endl;
			file << "PreventDetailGraphics = False" << std::endl;
			file << "GroundClutterRadius = 0" << std::endl;
			file << "HFSQuality = 0" << std::endl;
			file << "bMenuGyro = False" << std::endl;
			file << "gyroSensitivity = 0.500000" << std::endl;
			file << "virtualCursorSensitivity = 0.500000" << std::endl;
			file << "BubbleParticlesMultiplier = 1.000000" << std::endl;
			file << "CrosshairScale = 1.000000" << std::endl;
			file << "CrosshairOpacity = 1.000000" << std::endl;
			file << "CrosshairColor = (R = 1.000000, G = 1.000000, B = 1.000000, A = 1.000000)" << std::endl;
			file << "CrosshairColorPickerValue = (X = 0.000000, Y = 0.000000)" << std::endl;
			file << "CrosshairColorOverEnemy = (R = 0.000000, G = 0.376471, B = 1.000000, A = 1.000000)" << std::endl;
			file << "CrosshairColorPickerValueOverEnemy = (X = 0.010000, Y = 0.500000)" << std::endl;
			file << "CrosshairColorOverAlly = (R = 0.000000, G = 1.000000, B = 0.000000, A = 1.000000)" << std::endl;
			file << "CrosshairColorPickerValueOverAlly = (X = 0.260000, Y = 0.440000)" << std::endl;
			file << "CrosshairColorHitmark = (R = 1.000000, G = 0.000000, B = 0.000000, A = 1.000000)" << std::endl;
			file << "CrosshairColorPickerValueHitmark = (X = 0.010000, Y = 0.640000)" << std::endl;
			file << "CurrentCameraModeIndex = 2" << std::endl;
			file << "CurrentDinoCameraModeIndex = 1" << std::endl;
			file << "bShowAmbientInsectsVFX = True" << std::endl;
			file << "TextChatFilterType = 0" << std::endl;
			file << "VoiceChatFilterType = 0" << std::endl;
			file << "bAutomaticallyCreateWaypointOnTamingCreatures = True" << std::endl;
			file << "bAutomaticallyCreatePOIOnDeath = True" << std::endl;
			file << "bEnableDLSS = False" << std::endl;
			file << "bEnableDLFG = False" << std::endl;
			file << "bEnableReflex = True" << std::endl;
			file << "SuperResolutionQualityLevel = 0" << std::endl;
			file << "bOCIOIsEnabled = True" << std::endl;
			file << "OCIOAsset = / Game / ASA / Environment / Common / Color / OCIO_aces_v13_cg.OCIO_aces_v13_cg" << std::endl;
			file << "OCIOColorSpace = 0" << std::endl;
			file << "OCIODisplayView = 0" << std::endl;
			file << "bUseVSync = False" << std::endl;
			file << "bUseDynamicResolution = False" << std::endl;
			file << "ResolutionSizeX = 1280" << std::endl;
			file << "ResolutionSizeY = 720" << std::endl;
			file << "LastUserConfirmedResolutionSizeX = 1280" << std::endl;
			file << "LastUserConfirmedResolutionSizeY = 720" << std::endl;
			file << "WindowPosX = -1" << std::endl;
			file << "WindowPosY = -1" << std::endl;
			file << "FullscreenMode = 1" << std::endl;
			file << "LastConfirmedFullscreenMode = 1" << std::endl;
			file << "PreferredFullscreenMode = 1" << std::endl;
			file << "Version = 5" << std::endl;
			file << "AudioQualityLevel = 0" << std::endl;
			file << "LastConfirmedAudioQualityLevel = 0" << std::endl;
			file << "FrameRateLimit = 60.000000" << std::endl;
			file << "DesiredScreenWidth = 1280" << std::endl;
			file << "DesiredScreenHeight = 720" << std::endl;
			file << "LastUserConfirmedDesiredScreenWidth = 1280" << std::endl;
			file << "LastUserConfirmedDesiredScreenHeight = 720" << std::endl;
			file << "LastRecommendedScreenWidth = -1.000000" << std::endl;
			file << "LastRecommendedScreenHeight = -1.000000" << std::endl;
			file << "LastCPUBenchmarkResult = -1.000000" << std::endl;
			file << "LastGPUBenchmarkResult = -1.000000" << std::endl;
			file << "LastGPUBenchmarkMultiplier = 1.000000" << std::endl;
			file << "bUseHDRDisplayOutput = False" << std::endl;
			file << "HDRDisplayOutputNits = 1000" << std::endl;
			file << "" << std::endl;
			file << "[/Script/Engine.GameUserSettings]" << std::endl;
			file << "bUseDesiredScreenHeight = False" << std::endl;
			file << "" << std::endl;
			file << "[SessionSettings]" << std::endl;
			file << "SessionName = " << std::endl;
			file << "" << std::endl;
			file << "[/Script/Engine.GameSession]" << std::endl;
			file << "MaxPlayers = 70" << std::endl;
            
            file.close();
        }
    }
	System::Void INI::INI_Handler::EditLineInFile(System::String^ filePath, cli::array<System::String^>^ targetLines, const cli::array<System::String^>^ newLines) {
		std::string filePathStr = msclr::interop::marshal_as<std::string>(filePath);

		std::ifstream inputFile(filePathStr);
		if (!inputFile) {
			return;
		}

		std::ofstream outputFile(filePathStr + "//temp.txt");
		if (!outputFile) {
			inputFile.close();
			return;
		}

		std::string line;
		int lineIndex = 0;

		while (std::getline(inputFile, line)) {
			if (lineIndex < targetLines->Length) {
				System::String^ targetLine = targetLines[lineIndex];
				std::string targetLineStr = msclr::interop::marshal_as<std::string>(targetLine);

				if (line == targetLineStr) {
					System::String^ newLine = newLines[lineIndex];
					std::string newLineStr = msclr::interop::marshal_as<std::string, System::String^>(newLine);
					outputFile << newLineStr << std::endl;
					lineIndex++;
					continue;
				}
			}

			outputFile << line << std::endl;
		}

		inputFile.close();
		outputFile.close();

		if (std::remove(filePathStr.c_str()) != 0) {
			return;
		}

		if (std::rename((filePathStr + "//temp.txt").c_str(), filePathStr.c_str()) != 0) {
			return;
		}

		if (std::remove((filePathStr + "//temp.txt").c_str()) != 0) {
			return;
		}
	}
}