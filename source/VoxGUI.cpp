#include "VoxGame.h"
#include "utils/FileUtils.h"


void VoxGame::CreateGUI()
{
	m_pMainWindow = new GUIWindow(m_pRenderer, m_defaultFont, "Main");
	m_pMainWindow->AllowMoving(true);
	m_pMainWindow->AllowClosing(false);
	m_pMainWindow->AllowMinimizing(true);
	m_pMainWindow->AllowScrolling(true);
	m_pMainWindow->SetRenderTitleBar(true);
	m_pMainWindow->SetRenderWindowBackground(true);
	m_pMainWindow->SetOutlineRender(true);
	m_pMainWindow->SetDimensions(15, 35, 320, 140);
	m_pMainWindow->SetApplicationDimensions(m_windowWidth, m_windowHeight);

	m_pWireframeCheckBox = new CheckBox(m_pRenderer, m_defaultFont, "Wireframe");
	m_pWireframeCheckBox->SetDimensions(10, 10, 14, 14);
	m_pShadowsCheckBox = new CheckBox(m_pRenderer, m_defaultFont, "Shadows");
	m_pShadowsCheckBox->SetDimensions(10, 28, 14, 14);
	m_pMSAACheckBox = new CheckBox(m_pRenderer, m_defaultFont, "Anti-Aliasing");
	m_pMSAACheckBox->SetDimensions(10, 46, 14, 14);
	m_pDynamicLightingCheckBox = new CheckBox(m_pRenderer, m_defaultFont, "Lighting");
	m_pDynamicLightingCheckBox->SetDimensions(10, 64, 14, 14);
	m_pSSAOCheckBox = new CheckBox(m_pRenderer, m_defaultFont, "SSAO");
	m_pSSAOCheckBox->SetDimensions(10, 82, 14, 14);
	m_pBlurCheckBox = new CheckBox(m_pRenderer, m_defaultFont, "Blur");
	m_pBlurCheckBox->SetDimensions(10, 100, 14, 14);
	m_pDeferredCheckBox = new CheckBox(m_pRenderer, m_defaultFont, "Deferred");
	m_pDeferredCheckBox->SetDimensions(10, 118, 14, 14);
	m_pUpdateCheckBox = new CheckBox(m_pRenderer, m_defaultFont, "Update");
	m_pUpdateCheckBox->SetDimensions(110, 28, 14, 14);
	m_pUpdateCheckBox->SetToggled(true);
	m_pDebugRenderCheckBox = new CheckBox(m_pRenderer, m_defaultFont, "DebugRender");
	m_pDebugRenderCheckBox->SetDimensions(110, 10, 14, 14);
	m_pInstanceRenderCheckBox = new CheckBox(m_pRenderer, m_defaultFont, "Instance Particles");
	m_pInstanceRenderCheckBox->SetDimensions(110, 46, 14, 14);

	m_pFullscreenButton = new Button(m_pRenderer, m_defaultFont, "FullScreen");
	m_pFullscreenButton->SetDimensions(230, 10, 85, 25);
	m_pFullscreenButton->SetLabelColour(Colour(0.0f, 0.0f, 0.0f, 1.0f));
	m_pFullscreenButton->SetCallBackFunction(_ToggleFullScreenPressed);
	m_pFullscreenButton->SetCallBackData(this);

	m_pPlayAnimationButton = new Button(m_pRenderer, m_defaultFont, "Play Anim");
	m_pPlayAnimationButton->SetDimensions(230, 40, 85, 25);
	m_pPlayAnimationButton->SetLabelColour(Colour(0.0f, 0.0f, 0.0f, 1.0f));
	m_pPlayAnimationButton->SetCallBackFunction(_PlayAnimationPressed);
	m_pPlayAnimationButton->SetCallBackData(this);

	m_pAnimationsPulldown = new PulldownMenu(m_pRenderer, m_defaultFont, "Animation");
	m_pAnimationsPulldown->SetDimensions(150, 70, 140, 14);
	m_pAnimationsPulldown->SetMaxNumItemsDisplayed(5);
	m_pAnimationsPulldown->SetDepth(2.0f);
	m_pAnimationsPulldown->SetRenderHeader(true);
	m_pAnimationsPulldown->SetMenuItemChangedCallBackFunction(_AnimationPullDownChanged);
	m_pAnimationsPulldown->SetMenuItemChangedCallBackData(this);

	m_pWeaponsPulldown = new PulldownMenu(m_pRenderer, m_defaultFont, "Weapons");
	m_pWeaponsPulldown->SetDimensions(150, 93, 140, 14);
	m_pWeaponsPulldown->SetMaxNumItemsDisplayed(5);
	m_pWeaponsPulldown->SetDepth(3.0f);
	m_pWeaponsPulldown->SetRenderHeader(true);
	m_pWeaponsPulldown->SetMenuItemChangedCallBackFunction(_WeaponPullDownChanged);
	m_pWeaponsPulldown->SetMenuItemChangedCallBackData(this);
	m_pWeaponsPulldown->AddPulldownItem("None");
	m_pWeaponsPulldown->AddPulldownItem("Sword");
	m_pWeaponsPulldown->AddPulldownItem("Sword & Shield");
	m_pWeaponsPulldown->AddPulldownItem("2 Handed Sword");
	m_pWeaponsPulldown->AddPulldownItem("Hammer");
	m_pWeaponsPulldown->AddPulldownItem("Bow");
	m_pWeaponsPulldown->AddPulldownItem("Staff");
	m_pWeaponsPulldown->AddPulldownItem("DruidStaff");
	m_pWeaponsPulldown->AddPulldownItem("PriestStaff");
	m_pWeaponsPulldown->AddPulldownItem("NecroStaff");
	m_pWeaponsPulldown->AddPulldownItem("Torch");
	m_pWeaponsPulldown->AddPulldownItem("Magic");

	m_pCharacterPulldown = new PulldownMenu(m_pRenderer, m_defaultFont, "Character");
	m_pCharacterPulldown->SetDimensions(150, 115, 140, 14);
	m_pCharacterPulldown->SetMaxNumItemsDisplayed(5);
	m_pCharacterPulldown->SetDepth(4.0f);
	m_pCharacterPulldown->SetRenderHeader(true);
	m_pCharacterPulldown->SetMenuItemChangedCallBackFunction(_CharacterPullDownChanged);
	m_pCharacterPulldown->SetMenuItemChangedCallBackData(this);

	m_pMainWindow->AddComponent(m_pShadowsCheckBox);
	m_pMainWindow->AddComponent(m_pSSAOCheckBox);
	m_pMainWindow->AddComponent(m_pBlurCheckBox);
	m_pMainWindow->AddComponent(m_pDynamicLightingCheckBox);
	m_pMainWindow->AddComponent(m_pWireframeCheckBox);
	m_pMainWindow->AddComponent(m_pMSAACheckBox);
	m_pMainWindow->AddComponent(m_pDeferredCheckBox);
	m_pMainWindow->AddComponent(m_pUpdateCheckBox);
	m_pMainWindow->AddComponent(m_pDebugRenderCheckBox);
	m_pMainWindow->AddComponent(m_pInstanceRenderCheckBox);
	m_pMainWindow->AddComponent(m_pFullscreenButton);
	m_pMainWindow->AddComponent(m_pPlayAnimationButton);
	m_pMainWindow->AddComponent(m_pAnimationsPulldown);
	m_pMainWindow->AddComponent(m_pWeaponsPulldown);
	m_pMainWindow->AddComponent(m_pCharacterPulldown);

	m_pGameWindow = new GUIWindow(m_pRenderer, m_defaultFont, "Game");
	m_pGameWindow->AllowMoving(true);
	m_pGameWindow->AllowClosing(false);
	m_pGameWindow->AllowMinimizing(true);
	m_pGameWindow->AllowScrolling(true);
	m_pGameWindow->SetRenderTitleBar(true);
	m_pGameWindow->SetRenderWindowBackground(true);
	m_pGameWindow->SetOutlineRender(true);
	m_pGameWindow->SetDimensions(350, 35, 270, 140);
	m_pGameWindow->SetApplicationDimensions(m_windowWidth, m_windowHeight);

	m_pGameOptionBox = new OptionBox(m_pRenderer, m_defaultFont, "Game");
	m_pGameOptionBox->SetDimensions(10, 50, 14, 14);
	m_pGameOptionBox->SetCallBackFunction(_GameModeChanged);
	m_pGameOptionBox->SetCallBackData(this);
	m_pFrontEndOptionBox = new OptionBox(m_pRenderer, m_defaultFont, "Frontend");
	m_pFrontEndOptionBox->SetDimensions(10, 30, 14, 14);
	m_pFrontEndOptionBox->SetCallBackFunction(_GameModeChanged);
	m_pFrontEndOptionBox->SetCallBackData(this);
	m_pDebugOptionBox = new OptionBox(m_pRenderer, m_defaultFont, "Debug");
	m_pDebugOptionBox->SetDimensions(10, 10, 14, 14);
	m_pDebugOptionBox->SetCallBackFunction(_GameModeChanged);
	m_pDebugOptionBox->SetCallBackData(this);
	m_pGameModeOptionController = new OptionController(m_pRenderer, m_defaultFont, "Mode");
	m_pGameModeOptionController->SetDisplayLabel(true);
	m_pGameModeOptionController->SetDisplayBorder(true);
	m_pGameModeOptionController->SetDimensions(10, 55, 85, 70);
	m_pGameModeOptionController->Add(m_pGameOptionBox);
	m_pGameModeOptionController->Add(m_pDebugOptionBox);
	m_pGameModeOptionController->Add(m_pFrontEndOptionBox);
	m_pDebugOptionBox->SetToggled(true);

	m_pGUIThemePulldown = new PulldownMenu(m_pRenderer, m_defaultFont, "Theme");
	m_pGUIThemePulldown->SetDimensions(50, 30, 80, 14);
	m_pGUIThemePulldown->SetMaxNumItemsDisplayed(5);
	m_pGUIThemePulldown->SetDepth(2.0f);
	m_pGUIThemePulldown->SetRenderHeader(true);
	m_pGUIThemePulldown->SetMenuItemChangedCallBackFunction(_GUIThemePullDownChanged);
	m_pGUIThemePulldown->SetMenuItemChangedCallBackData(this);

	m_pFaceMergingCheckbox = new CheckBox(m_pRenderer, m_defaultFont, "Face Merging");
	m_pFaceMergingCheckbox->SetDimensions(10, 10, 14, 14);
	m_pFaceMergingCheckbox->SetCallBackFunction(_FaceMergeCheckboxChanged);
	m_pFaceMergingCheckbox->SetCallBackData(this);

	m_pStepUpdateCheckbox = new CheckBox(m_pRenderer, m_defaultFont, "Step Update");
	m_pStepUpdateCheckbox->SetDimensions(110, 10, 14, 14);

	m_pStepUpdateButton = new Button(m_pRenderer, m_defaultFont, "Step");
	m_pStepUpdateButton->SetDimensions(200, 5, 85, 25);
	m_pStepUpdateButton->SetLabelColour(Colour(0.0f, 0.0f, 0.0f, 1.0f));
	m_pStepUpdateButton->SetCallBackFunction(_StepUpdatePressed);
	m_pStepUpdateButton->SetCallBackData(this);

	m_pDebugCameraOptionBox = new OptionBox(m_pRenderer, m_defaultFont, "Debug");
	m_pDebugCameraOptionBox->SetDimensions(10, 70, 14, 14);
	m_pDebugCameraOptionBox->SetCallBackFunction(_CameraModeChanged);
	m_pDebugCameraOptionBox->SetCallBackData(this);
	m_pMouseRotateCameraOptionBox = new OptionBox(m_pRenderer, m_defaultFont, "Player Rotate");
	m_pMouseRotateCameraOptionBox->SetDimensions(10, 50, 14, 14);
	m_pMouseRotateCameraOptionBox->SetCallBackFunction(_CameraModeChanged);
	m_pMouseRotateCameraOptionBox->SetCallBackData(this);
	m_pAutoCameraOptionBox = new OptionBox(m_pRenderer, m_defaultFont, "Auto");
	m_pAutoCameraOptionBox->SetDimensions(10, 30, 14, 14);
	m_pAutoCameraOptionBox->SetCallBackFunction(_CameraModeChanged);
	m_pAutoCameraOptionBox->SetCallBackData(this);
	m_pFirstPersonCameraOptionBox = new OptionBox(m_pRenderer, m_defaultFont, "First Person");
	m_pFirstPersonCameraOptionBox->SetDimensions(10, 10, 14, 14);
	m_pFirstPersonCameraOptionBox->SetCallBackFunction(_CameraModeChanged);
	m_pFirstPersonCameraOptionBox->SetCallBackData(this);
	m_pCameraModeOptionController = new OptionController(m_pRenderer, m_defaultFont, "Camera");
	m_pCameraModeOptionController->SetDisplayLabel(true);
	m_pCameraModeOptionController->SetDisplayBorder(true);
	m_pCameraModeOptionController->SetDimensions(160, 35, 105, 90);
	m_pCameraModeOptionController->Add(m_pDebugCameraOptionBox);
	m_pCameraModeOptionController->Add(m_pMouseRotateCameraOptionBox);
	m_pCameraModeOptionController->Add(m_pAutoCameraOptionBox);
	m_pCameraModeOptionController->Add(m_pFirstPersonCameraOptionBox);
	m_pDebugCameraOptionBox->SetToggled(true);
	m_pMouseRotateCameraOptionBox->SetDisabled(true);
	m_pAutoCameraOptionBox->SetDisabled(true);
	m_pFirstPersonCameraOptionBox->SetDisabled(true);

	m_pGameWindow->AddComponent(m_pGameModeOptionController);
	m_pGameWindow->AddComponent(m_pGUIThemePulldown);
	m_pGameWindow->AddComponent(m_pCameraModeOptionController);
	m_pGameWindow->AddComponent(m_pFaceMergingCheckbox);
	m_pGameWindow->AddComponent(m_pStepUpdateCheckbox);
	m_pGameWindow->AddComponent(m_pStepUpdateButton);

	// Console window
	m_pConsoleWindow = new GUIWindow(m_pRenderer, m_defaultFont, "Console");
	m_pConsoleWindow->AllowMoving(true);
	m_pConsoleWindow->AllowClosing(false);
	m_pConsoleWindow->AllowMinimizing(true);
	m_pConsoleWindow->AllowScrolling(true);
	m_pConsoleWindow->SetRenderTitleBar(true);
	m_pConsoleWindow->SetRenderWindowBackground(true);
	m_pConsoleWindow->SetOutlineRender(true);
	m_pConsoleWindow->SetDimensions(635, 35, 500, 140);
	m_pConsoleWindow->SetApplicationDimensions(m_windowWidth, m_windowHeight);

	m_pConsoleTextbox = new TextBox(m_pRenderer, m_defaultFont, "", "");
	m_pConsoleTextbox->SetDimensions(0, 0, 500, 18);
	m_pConsoleTextbox->SetDontLoseFocus(false);
	m_pConsoleTextbox->SetCallBackFunction_OnReturnPressed(_ConsoleReturnPressed);
	m_pConsoleTextbox->SetCallBackData_OnReturnPressed(this);
	m_pConsoleTextbox->SetPipeColour(Colour(0.0f, 0.0f, 0.0f));
	m_pConsoleTextbox->SetDontLoseFocus(true);

	m_pConsoleScrollbar = new ScrollBar(m_pRenderer);
	m_pConsoleScrollbar->SetScrollDirection(EScrollBarDirection_Vertical);
	m_pConsoleScrollbar->SetScrollSize(1.0f);
	m_pConsoleScrollbar->SetScrollPosition(1.0f);
	m_pConsoleScrollbar->SetScissorEnabled(true);
	m_pConsoleScrollbar->SetScrollArea(-484, 0, 490, 122);
	m_pConsoleScrollbar->SetDepth(2.0f);
	m_pConsoleScrollbar->SetDimensions(486, 18, 14, 122);
	m_pConsoleScrollbar->SetScissorEnabled(true);

	m_pConsoleWindow->AddComponent(m_pConsoleTextbox);
	m_pConsoleWindow->AddComponent(m_pConsoleScrollbar);

	m_pGUI->AddWindow(m_pMainWindow);
	m_pGUI->AddWindow(m_pGameWindow);
	m_pGUI->AddWindow(m_pConsoleWindow);

	UpdateCharactersPulldown();
	UpdateWeaponsPulldown();
	UpdateAnimationsPulldown();
	UpdateGUIThemePulldown();

	m_pCharacterPulldown->SetSelectedItem("Steve");
	m_pWeaponsPulldown->SetSelectedItem("None");
	m_pAnimationsPulldown->SetSelectedItem("BindPose");
	m_pGUIThemePulldown->SetSelectedItem("Default");

	m_GUICreated = true;
}

void VoxGame::SetupGUI()
{
	m_pDeferredCheckBox->SetToggled(m_pVoxSettings->m_deferredRendering);
	m_pShadowsCheckBox->SetToggled(m_pVoxSettings->m_shadows);
	m_pSSAOCheckBox->SetToggled(m_pVoxSettings->m_ssao);
	m_pBlurCheckBox->SetToggled(m_pVoxSettings->m_blur);
	m_pDynamicLightingCheckBox->SetToggled(m_pVoxSettings->m_dynamicLighting);
	m_pMSAACheckBox->SetToggled(m_pVoxSettings->m_msaa);
	m_pInstanceRenderCheckBox->SetToggled(m_pVoxSettings->m_instancedParticles);
	m_pWireframeCheckBox->SetToggled(m_pVoxSettings->m_wireframeRendering);
	m_pDebugRenderCheckBox->SetToggled(m_pVoxSettings->m_debugRendering);
	m_pFaceMergingCheckbox->SetToggled(m_pVoxSettings->m_faceMerging);
	m_pStepUpdateCheckbox->SetToggled(m_pVoxSettings->m_stepUpdating);

	// Debug GUI
	if(m_pVoxSettings->m_showDebugGUI)
	{
		ShowGUI();
	}
	else
	{
		HideGUI();
	}

	// Game mode
	if (strcmp(m_pVoxSettings->m_gameMode.c_str(), "Debug") == 0)
	{
		m_pDebugOptionBox->SetToggled(true);
	}
	else if (strcmp(m_pVoxSettings->m_gameMode.c_str(), "Game") == 0)
	{
		m_pGameOptionBox->SetToggled(true);
		m_pMouseRotateCameraOptionBox->SetToggled(true);
	}
	else if (strcmp(m_pVoxSettings->m_gameMode.c_str(), "FrontEnd") == 0)
	{
		m_pFrontEndOptionBox->SetToggled(true);
	}
	m_pVoxWindow->Update(m_deltaTime);
	GameModeChanged();
	CameraModeChanged();
}

void VoxGame::SkinGUI()
{
	m_pFrontendManager->SetCheckboxIcons(m_pShadowsCheckBox);
	m_pFrontendManager->SetCheckboxIcons(m_pMSAACheckBox);
	m_pFrontendManager->SetCheckboxIcons(m_pDynamicLightingCheckBox);
	m_pFrontendManager->SetCheckboxIcons(m_pSSAOCheckBox);
	m_pFrontendManager->SetCheckboxIcons(m_pBlurCheckBox);
	m_pFrontendManager->SetCheckboxIcons(m_pDeferredCheckBox);
	m_pFrontendManager->SetCheckboxIcons(m_pWireframeCheckBox);
	m_pFrontendManager->SetCheckboxIcons(m_pFaceMergingCheckbox);
	m_pFrontendManager->SetCheckboxIcons(m_pStepUpdateCheckbox);
	m_pFrontendManager->SetCheckboxIcons(m_pUpdateCheckBox);
	m_pFrontendManager->SetCheckboxIcons(m_pDebugRenderCheckBox);
	m_pFrontendManager->SetCheckboxIcons(m_pInstanceRenderCheckBox);

	m_pFrontendManager->SetOptionboxIcons(m_pGameOptionBox);
	m_pFrontendManager->SetOptionboxIcons(m_pDebugOptionBox);
	m_pFrontendManager->SetOptionboxIcons(m_pFrontEndOptionBox);

	m_pFrontendManager->SetOptionboxIcons(m_pDebugCameraOptionBox);
	m_pFrontendManager->SetOptionboxIcons(m_pMouseRotateCameraOptionBox);
	m_pFrontendManager->SetOptionboxIcons(m_pAutoCameraOptionBox);
	m_pFrontendManager->SetOptionboxIcons(m_pFirstPersonCameraOptionBox);

	m_pFrontendManager->SetPulldownMenuIcons(m_pAnimationsPulldown);
	m_pFrontendManager->SetPulldownMenuIcons(m_pWeaponsPulldown);
	m_pFrontendManager->SetPulldownMenuIcons(m_pCharacterPulldown);
	m_pFrontendManager->SetPulldownMenuIcons(m_pGUIThemePulldown);

	m_pFrontendManager->SetScrollbarIcons(m_pConsoleScrollbar);

	m_pFrontendManager->SetButtonIcons(m_pFullscreenButton, ButtonSize_85x25);
	m_pFrontendManager->SetButtonIcons(m_pPlayAnimationButton, ButtonSize_85x25);
	m_pFrontendManager->SetButtonIcons(m_pStepUpdateButton, ButtonSize_85x25);
}

void VoxGame::UnSkinGUI()
{
	m_pShadowsCheckBox->SetDefaultIcons(m_pRenderer);
	m_pMSAACheckBox->SetDefaultIcons(m_pRenderer);
	m_pDynamicLightingCheckBox->SetDefaultIcons(m_pRenderer);
	m_pSSAOCheckBox->SetDefaultIcons(m_pRenderer);
	m_pBlurCheckBox->SetDefaultIcons(m_pRenderer);
	m_pDeferredCheckBox->SetDefaultIcons(m_pRenderer);
	m_pWireframeCheckBox->SetDefaultIcons(m_pRenderer);
	m_pFaceMergingCheckbox->SetDefaultIcons(m_pRenderer);
	m_pStepUpdateCheckbox->SetDefaultIcons(m_pRenderer);
	m_pUpdateCheckBox->SetDefaultIcons(m_pRenderer);
	m_pDebugRenderCheckBox->SetDefaultIcons(m_pRenderer);
	m_pInstanceRenderCheckBox->SetDefaultIcons(m_pRenderer);

	m_pGameOptionBox->SetDefaultIcons(m_pRenderer);
	m_pDebugOptionBox->SetDefaultIcons(m_pRenderer);
	m_pFrontEndOptionBox->SetDefaultIcons(m_pRenderer);

	m_pAnimationsPulldown->SetDefaultIcons(m_pRenderer);
	m_pWeaponsPulldown->SetDefaultIcons(m_pRenderer);
	m_pCharacterPulldown->SetDefaultIcons(m_pRenderer);
	m_pGUIThemePulldown->SetDefaultIcons(m_pRenderer);

	m_pDebugCameraOptionBox->SetDefaultIcons(m_pRenderer);
	m_pMouseRotateCameraOptionBox->SetDefaultIcons(m_pRenderer);
	m_pAutoCameraOptionBox->SetDefaultIcons(m_pRenderer);
	m_pFirstPersonCameraOptionBox->SetDefaultIcons(m_pRenderer);

	m_pFullscreenButton->SetDefaultIcons(m_pRenderer);
	m_pPlayAnimationButton->SetDefaultIcons(m_pRenderer);
	m_pStepUpdateButton->SetDefaultIcons(m_pRenderer);

	m_pConsoleScrollbar->SetDefaultIcons(m_pRenderer);
}

void VoxGame::DestroyGUI()
{
	delete m_pMainWindow;
	delete m_pShadowsCheckBox;
	delete m_pSSAOCheckBox;
	delete m_pBlurCheckBox;
	delete m_pDynamicLightingCheckBox;
	delete m_pWireframeCheckBox;
	delete m_pMSAACheckBox;
	delete m_pDeferredCheckBox;
	delete m_pUpdateCheckBox;
	delete m_pDebugRenderCheckBox;
	delete m_pInstanceRenderCheckBox;
	delete m_pFullscreenButton;
	delete m_pPlayAnimationButton;
	delete m_pAnimationsPulldown;
	delete m_pWeaponsPulldown;
	delete m_pCharacterPulldown;
	delete m_pGameWindow;
	delete m_pGameOptionBox;
	delete m_pDebugOptionBox;
	delete m_pFrontEndOptionBox;
	delete m_pGameModeOptionController;
	delete m_pGUIThemePulldown;
	delete m_pFaceMergingCheckbox;
	delete m_pStepUpdateCheckbox;
	delete m_pStepUpdateButton;
	delete m_pDebugCameraOptionBox;
	delete m_pMouseRotateCameraOptionBox;
	delete m_pAutoCameraOptionBox;
	delete m_pFirstPersonCameraOptionBox;
	delete m_pCameraModeOptionController;
	delete m_pConsoleWindow;
	delete m_pConsoleTextbox;
	ClearConsoleLabels();
	delete m_pConsoleScrollbar;
}

void VoxGame::UpdateGUI(float dt)
{
	// Depending on if deferred rendering is enabled, allow or disallow certain other graphic features
	if (m_deferredRendering)
	{
		m_pSSAOCheckBox->SetDisabled(false);
		m_pDynamicLightingCheckBox->SetDisabled(false);
		m_pBlurCheckBox->SetDisabled(false);
	}
	else
	{
		m_pSSAOCheckBox->SetDisabled(true);
		m_pDynamicLightingCheckBox->SetDisabled(true);
		m_pBlurCheckBox->SetDisabled(true);
		m_pMSAACheckBox->SetDisabled(false);
	}

	// If shaders are not loaded, then disable some graphical features
	if (m_SSAOShader == -1)
	{
		m_pSSAOCheckBox->SetToggled(false);
		m_pSSAOCheckBox->SetDisabled(true);
		m_pDeferredCheckBox->SetToggled(false);
		m_pDeferredCheckBox->SetDisabled(true);
		m_pDynamicLightingCheckBox->SetToggled(false);
		m_pDynamicLightingCheckBox->SetDisabled(true);
	}
	if (m_lightingShader == -1)
	{
		m_pDynamicLightingCheckBox->SetToggled(false);
		m_pDynamicLightingCheckBox->SetDisabled(true);
	}
	if (m_shadowShader == -1)
	{
		m_pShadowsCheckBox->SetToggled(false);
		m_pShadowsCheckBox->SetDisabled(true);
	}
	if (m_pBlockParticleManager->GetInstanceShaderIndex() == -1)
	{
		m_pInstanceRenderCheckBox->SetToggled(false);
		m_pInstanceRenderCheckBox->SetDisabled(true);
	}
	if (m_fxaaShader == -1 && m_deferredRendering)
	{
		m_pMSAACheckBox->SetToggled(false);
		m_pMSAACheckBox->SetDisabled(true);
	}
	if (m_blurVerticalShader == -1 || m_blurHorizontalShader == -1)
	{
		m_pBlurCheckBox->SetToggled(false);
		m_pBlurCheckBox->SetDisabled(true);
	}

	m_shadows = m_pShadowsCheckBox->GetToggled();
	m_ssao = m_pSSAOCheckBox->GetToggled();
	m_blur = m_pBlurCheckBox->GetToggled();
	m_dynamicLighting = m_pDynamicLightingCheckBox->GetToggled();
	m_modelWireframe = m_pWireframeCheckBox->GetToggled();
	m_multiSampling = m_pMSAACheckBox->GetToggled();
	m_deferredRendering = m_pDeferredCheckBox->GetToggled();
	m_animationUpdate = m_pUpdateCheckBox->GetToggled();
	m_debugRender = m_pDebugRenderCheckBox->GetToggled();
	m_instanceRender = m_pInstanceRenderCheckBox->GetToggled();

	m_pPlayer->SetWireFrameRender(m_modelWireframe);
	m_pChunkManager->SetWireframeRender(m_modelWireframe);
	m_pChunkManager->SetFaceMerging(m_pFaceMergingCheckbox->GetToggled());
	m_pChunkManager->SetStepLockEnabled(m_pStepUpdateCheckbox->GetToggled());
	m_pBlockParticleManager->SetWireFrameRender(m_modelWireframe);
	m_pBlockParticleManager->SetInstancedRendering(m_instanceRender);

	
	// Update console
	UpdateConsoleLabels();
}

void VoxGame::GUITurnOffCursor()
{
	m_pGUI->ResetSelectionManager();
}

void VoxGame::ShowGUI()
{
	if (m_pMainWindow->IsVisible() == false)
	{
		m_pMainWindow->Show();
	}
	if (m_pGameWindow->IsVisible() == false)
	{
		m_pGameWindow->Show();
	}
	if (m_pConsoleWindow->IsVisible() == false)
	{
		m_pConsoleWindow->Show();
	}
}

void VoxGame::HideGUI()
{
	if (m_pMainWindow->IsVisible() == true)
	{
		m_pMainWindow->Hide();
	}
	if (m_pGameWindow->IsVisible() == true)
	{
		m_pGameWindow->Hide();
	}
	if (m_pConsoleWindow->IsVisible() == true)
	{
		m_pConsoleWindow->Hide();
	}
}

void VoxGame::UpdateCharactersPulldown()
{
	m_pCharacterPulldown->RemoveAllPullDownMenuItems();
	m_pCharacterPulldown->ResetPullDownMenu();
	m_pMainWindow->RemoveComponent(m_pCharacterPulldown);

	char importDirectory[128];
	snprintf(importDirectory, 128, "media/gamedata/models/Human/*.qb");

	vector<string> listFiles;
	listFiles = listFilesInDirectory(importDirectory);
	for (unsigned int i = 0; i < listFiles.size(); i++)
	{
		int lastindex = (int)listFiles[i].find_last_of(".");
		string characterName = listFiles[i].substr(0, lastindex);
		m_pCharacterPulldown->AddPulldownItem(characterName);
	}

	m_pMainWindow->AddComponent(m_pCharacterPulldown);
	m_pCharacterPulldown->AddEventListeners();
}

void VoxGame::UpdateWeaponsPulldown()
{
}

void VoxGame::UpdateAnimationsPulldown()
{
	m_pAnimationsPulldown->RemoveAllPullDownMenuItems();
	m_pAnimationsPulldown->ResetPullDownMenu();
	m_pMainWindow->RemoveComponent(m_pAnimationsPulldown);

	for (int i = 0; i < m_pPlayer->GetVoxelCharacter()->GetNumAnimations(); i++)
	{
		m_pAnimationsPulldown->AddPulldownItem(m_pPlayer->GetVoxelCharacter()->GetAnimationName(i));
	}

	m_pMainWindow->AddComponent(m_pAnimationsPulldown);
	m_pAnimationsPulldown->AddEventListeners();
}

void VoxGame::UpdateGUIThemePulldown()
{
	m_pGUIThemePulldown->RemoveAllPullDownMenuItems();
	m_pGUIThemePulldown->ResetPullDownMenu();
	m_pGameWindow->RemoveComponent(m_pGUIThemePulldown);

	// Add 'None' theme to use standard GUI rendering
	m_pGUIThemePulldown->AddPulldownItem("None");

	char importDirectory[128];
	snprintf(importDirectory, 128, "media/textures/gui/*.*");

	vector<string> listFiles;
	listFiles = listFilesInDirectory(importDirectory);
	for (unsigned int i = 0; i < listFiles.size(); i++)
	{
		if (strcmp(listFiles[i].c_str(), ".") == 0 || strcmp(listFiles[i].c_str(), "..") == 0)
		{
			continue;
		}

		m_pGUIThemePulldown->AddPulldownItem(listFiles[i].c_str());
	}

	m_pGameWindow->AddComponent(m_pGUIThemePulldown);
	m_pGUIThemePulldown->AddEventListeners();
}

void VoxGame::AddConsoleLabel(string message)
{
	if (m_GUICreated == false)
	{
		m_vStringCache.push_back(message);

		return;
	}

	char lChatString[8192];
	snprintf(lChatString, 8192, "%s", message.c_str());

	string chatString = lChatString;

	int lCharIndex = 0;
	int lStartLineIndex = 0;
	int lPreviousSpaceIndex = 0;

	// Our position
	float lCurrentTextX = 0.0f;
	int newLineIndex = 1;

	int indexToUse = (int)m_vpConsoleLabels.size() + (int)m_vpConsoleLabels_Add.size();

	while (lChatString[lCharIndex] != 0)
	{
		char lpChar = lChatString[lCharIndex];
		char lpNextChar = lChatString[lCharIndex + 1];

		// Check for spaces
		if (lpChar == ' ')
		{
			string lString(chatString.substr(lStartLineIndex, lCharIndex - lStartLineIndex));
			int lTextLineWidth = m_pRenderer->GetFreeTypeTextWidth(m_defaultFont, "%s", lString.c_str());

			// If the current X position, plus our new text length is greater than the width, then we know we will go out of bounds
			if (lCurrentTextX + lTextLineWidth > m_pConsoleScrollbar->GetScrollArea().m_width)
			{
				string lString(chatString.substr(lStartLineIndex, lPreviousSpaceIndex - lStartLineIndex));

				Label* pNewLabel = new Label(m_pRenderer, m_defaultFont, lString.c_str(), Colour(1.0f, 1.0f, 1.0f));
				int xPos = m_pConsoleScrollbar->GetScrollArea().m_x;
				int yPos = m_pConsoleScrollbar->GetScrollArea().m_y + m_pConsoleScrollbar->GetScrollArea().m_height - (indexToUse + newLineIndex) * 14;
				pNewLabel->SetLocation(xPos, yPos);

				m_vpConsoleLabels_Add.push_back(pNewLabel);

				// Skip over the new line, else we will detect it on the next loop
				lStartLineIndex = lPreviousSpaceIndex + 1;
				newLineIndex++;
			}

			lPreviousSpaceIndex = lCharIndex;
		}

		// Check for the end of the string
		if (lpNextChar == 0)
		{
			string lString(chatString.substr(lStartLineIndex, lCharIndex + 1 - lStartLineIndex));
			int lTextLineWidth = m_pRenderer->GetFreeTypeTextWidth(m_defaultFont, "%s", lString.c_str());

			Label* pNewLabel = new Label(m_pRenderer, m_defaultFont, lString.c_str(), Colour(1.0f, 1.0f, 1.0f));
			int xPos = m_pConsoleScrollbar->GetScrollArea().m_x;
			int yPos = m_pConsoleScrollbar->GetScrollArea().m_y + m_pConsoleScrollbar->GetScrollArea().m_height - (indexToUse + newLineIndex) * 14;
			pNewLabel->SetLocation(xPos, yPos);

			m_vpConsoleLabels_Add.push_back(pNewLabel);
		}

		lCharIndex++;
	}
}

void VoxGame::ClearConsoleLabels()
{
	m_pConsoleScrollbar->ClearScrollAreaItems();

	for (int i = 0; i < (int)m_vpConsoleLabels.size(); i++)
	{
		delete m_vpConsoleLabels[i];
		m_vpConsoleLabels[i] = 0;
	}
	m_vpConsoleLabels.clear();
}

void VoxGame::UpdateConsoleLabels()
{
	if (m_GUICreated == false)
	{
		return;
	}
	else
	{
		for (int i = 0; i < (int)m_vStringCache.size(); i++)
		{
			AddConsoleLabel(m_vStringCache[i]);
		}
		m_vStringCache.clear();
	}

	// Add to GUI
	for (int i = 0; i < (int)m_vpConsoleLabels_Add.size(); i++)
	{
		m_vpConsoleLabels.push_back(m_vpConsoleLabels_Add[i]);
		m_pConsoleScrollbar->AddScrollAreaItem(m_vpConsoleLabels_Add[i]);
		m_pConsoleScrollbar->SetScrollPosition(0.0f);
	}
	m_vpConsoleLabels_Add.clear();

	// Update scrollbar and scroll items
	int visibleSize = m_pConsoleScrollbar->GetScrollArea().m_height;
	int neededHeight = (int)m_vpConsoleLabels.size() * 14 + 5;
	int heightDiff = neededHeight - visibleSize;
	if (heightDiff > 0)
	{
		m_pConsoleScrollbar->SetScrollSize((float)visibleSize / (float)neededHeight);
		m_pConsoleScrollbar->SetDisabled(false);

		float scrollRatio = m_pConsoleScrollbar->GetScrollRatio();
		int offsetButtonY = (int)(heightDiff * scrollRatio);

		for (unsigned int i = 0; i < m_vpConsoleLabels.size(); i++)
		{
			int xPos = m_pConsoleScrollbar->GetScrollArea().m_x;
			int yPos = visibleSize - 14 - (i * 14);

			m_vpConsoleLabels[i]->SetLocation(xPos, yPos + offsetButtonY);
		}
	}
	else
	{
		m_pConsoleScrollbar->SetScrollSize(0.0f);
		m_pConsoleScrollbar->SetDisabled(true);
	}
}

// GUI callbacks
void VoxGame::_ToggleFullScreenPressed(void *apData)
{
	VoxGame* lpVoxGame = (VoxGame*)apData;
	lpVoxGame->ToggleFullScreenPressed();
}

void VoxGame::ToggleFullScreenPressed()
{
	m_fullscreen = !m_fullscreen;

	m_pVoxWindow->ToggleFullScreen(m_fullscreen);
	m_pBlockParticleManager->SetupGLBuffers();
}

void VoxGame::_PlayAnimationPressed(void *apData)
{
	VoxGame* lpVoxGame = (VoxGame*)apData;
	lpVoxGame->PlayAnimationPressed();
}

void VoxGame::PlayAnimationPressed()
{
	AnimationPullDownChanged();
}

void VoxGame::_AnimationPullDownChanged(void *apData)
{
	VoxGame* lpVoxGame = (VoxGame*)apData;
	lpVoxGame->AnimationPullDownChanged();
}

void VoxGame::AnimationPullDownChanged()
{
	MenuItem* pMenuItem = m_pAnimationsPulldown->GetSelectedMenuItem();
	if (pMenuItem != NULL)
	{
		m_pPlayer->GetVoxelCharacter()->PlayAnimation(AnimationSections_FullBody, false, AnimationSections_FullBody, pMenuItem->GetLabel().GetText().c_str());
	}
}

void VoxGame::_WeaponPullDownChanged(void *apData)
{
	VoxGame* lpVoxGame = (VoxGame*)apData;
	lpVoxGame->WeaponPullDownChanged();
}

void VoxGame::WeaponPullDownChanged()
{
	m_pPlayer->UnloadWeapon(true);
	m_pPlayer->UnloadWeapon(false);
	m_pPlayer->GetVoxelCharacter()->SetQubicleMatrixRender("Right_Hand", true);
	m_pPlayer->GetVoxelCharacter()->SetQubicleMatrixRender("Left_Hand", true);

	MenuItem* pMenuItem = m_pWeaponsPulldown->GetSelectedMenuItem();
	if (pMenuItem != NULL)
	{
		if (strcmp(pMenuItem->GetLabel().GetText().c_str(), "NONE") == 0)
		{
		}
		else if (strcmp(pMenuItem->GetLabel().GetText().c_str(), "Sword") == 0)
		{
			m_pPlayer->GetVoxelCharacter()->LoadRightWeapon("media/gamedata/weapons/Sword/Sword.weapon");
		}
		else if (strcmp(pMenuItem->GetLabel().GetText().c_str(), "Sword & Shield") == 0)
		{
			m_pPlayer->GetVoxelCharacter()->LoadRightWeapon("media/gamedata/weapons/Sword/Sword.weapon");
			m_pPlayer->GetVoxelCharacter()->LoadLeftWeapon("media/gamedata/weapons/Shield/Shield.weapon");
		}
		else if (strcmp(pMenuItem->GetLabel().GetText().c_str(), "2 Handed Sword") == 0)
		{
			m_pPlayer->GetVoxelCharacter()->LoadRightWeapon("media/gamedata/weapons/2HandedSword/2HandedSword.weapon");
		}
		else if (strcmp(pMenuItem->GetLabel().GetText().c_str(), "Hammer") == 0)
		{
			m_pPlayer->GetVoxelCharacter()->LoadRightWeapon("media/gamedata/weapons/Hammer/Hammer.weapon");
		}
		else if (strcmp(pMenuItem->GetLabel().GetText().c_str(), "Bow") == 0)
		{
			m_pPlayer->GetVoxelCharacter()->LoadLeftWeapon("media/gamedata/weapons/Bow/Bow.weapon");
		}
		else if (strcmp(pMenuItem->GetLabel().GetText().c_str(), "Staff") == 0)
		{
			m_pPlayer->GetVoxelCharacter()->LoadRightWeapon("media/gamedata/weapons/Staff/Staff.weapon");
		}
		else if (strcmp(pMenuItem->GetLabel().GetText().c_str(), "DruidStaff") == 0)
		{
			m_pPlayer->GetVoxelCharacter()->LoadRightWeapon("media/gamedata/weapons/DruidStaff/DruidStaff.weapon");
		}
		else if (strcmp(pMenuItem->GetLabel().GetText().c_str(), "PriestStaff") == 0)
		{
			m_pPlayer->GetVoxelCharacter()->LoadRightWeapon("media/gamedata/weapons/PriestStaff/PriestStaff.weapon");
		}
		else if (strcmp(pMenuItem->GetLabel().GetText().c_str(), "NecroStaff") == 0)
		{
			m_pPlayer->GetVoxelCharacter()->LoadRightWeapon("media/gamedata/weapons/NecroStaff/NecroStaff.weapon");
		}
		else if (strcmp(pMenuItem->GetLabel().GetText().c_str(), "Torch") == 0)
		{
			m_pPlayer->GetVoxelCharacter()->LoadRightWeapon("media/gamedata/weapons/Torch/Torch.weapon");
		}
		else if (strcmp(pMenuItem->GetLabel().GetText().c_str(), "Magic") == 0)
		{
			m_pPlayer->GetVoxelCharacter()->LoadRightWeapon("media/gamedata/weapons/FireballHands/FireballHandsRight.weapon");
			m_pPlayer->GetVoxelCharacter()->LoadLeftWeapon("media/gamedata/weapons/FireballHands/FireballHandsLeft.weapon");
			m_pPlayer->GetVoxelCharacter()->SetQubicleMatrixRender("Right_Hand", false);
			m_pPlayer->GetVoxelCharacter()->SetQubicleMatrixRender("Left_Hand", false);
		}
	}
}

void VoxGame::_CharacterPullDownChanged(void *apData)
{
	VoxGame* lpVoxGame = (VoxGame*)apData;
	lpVoxGame->CharacterPullDownChanged();
}

void VoxGame::CharacterPullDownChanged()
{
	MenuItem* pMenuItem = m_pCharacterPulldown->GetSelectedMenuItem();
	if (pMenuItem != NULL)
	{
		m_pPlayer->UnloadWeapon(false);
		m_pPlayer->UnloadWeapon(true);

		m_pPlayer->LoadCharacter(pMenuItem->GetLabel().GetText().c_str());

		WeaponPullDownChanged();
		AnimationPullDownChanged();
	}
}

void VoxGame::_GameModeChanged(void *apData)
{
	VoxGame* lpVoxGame = (VoxGame*)apData;
	lpVoxGame->GameModeChanged();
}

void VoxGame::GameModeChanged()
{
	GameMode gameMode = GetGameMode();

	if (m_pGameOptionBox->GetToggled() && gameMode != GameMode_Game)
	{
		SetGameMode(GameMode_Game);

		m_pMouseRotateCameraOptionBox->SetDisabled(false);
		m_pAutoCameraOptionBox->SetDisabled(false);
		m_pFirstPersonCameraOptionBox->SetDisabled(false);
	}
	else if (m_pFrontEndOptionBox->GetToggled() && gameMode != GameMode_FrontEnd)
	{
		SetGameMode(GameMode_FrontEnd);

		m_pMouseRotateCameraOptionBox->SetDisabled(true);
		m_pAutoCameraOptionBox->SetDisabled(true);
		m_pFirstPersonCameraOptionBox->SetDisabled(true);
	}
	else if (m_pDebugOptionBox->GetToggled() && gameMode != GameMode_Debug)
	{
		SetGameMode(GameMode_Debug);

		m_cameraMode = CameraMode_Debug;
		m_pDebugCameraOptionBox->SetToggled(true);

		m_pMouseRotateCameraOptionBox->SetDisabled(true);
		m_pAutoCameraOptionBox->SetDisabled(true);
		m_pFirstPersonCameraOptionBox->SetDisabled(true);
	}
}

void VoxGame::_CameraModeChanged(void *apData)
{
	VoxGame* lpVoxGame = (VoxGame*)apData;
	lpVoxGame->CameraModeChanged();
}

void VoxGame::CameraModeChanged()
{
	if (m_pDebugCameraOptionBox->GetToggled())
	{
		SetCameraMode(CameraMode_Debug);

		m_pVoxWindow->TurnCursorOn(true);
	}
	else if (m_pMouseRotateCameraOptionBox->GetToggled())
	{
		SetCameraMode(CameraMode_MouseRotate);
		InitializeCameraRotation();

		m_pVoxWindow->TurnCursorOff();
	}
	else if (m_pAutoCameraOptionBox->GetToggled())
	{
		SetCameraMode(CameraMode_AutoCamera);
		InitializeCameraRotation();

		m_pVoxWindow->TurnCursorOff();
	}
	else if (m_pFirstPersonCameraOptionBox->GetToggled())
	{
		SetCameraMode(CameraMode_FirstPerson);

		m_pVoxWindow->TurnCursorOff();
	}
}

void VoxGame::_GUIThemePullDownChanged(void *apData)
{
	VoxGame* lpVoxGame = (VoxGame*)apData;
	lpVoxGame->GUIThemePullDownChanged();
}

void VoxGame::GUIThemePullDownChanged()
{
	MenuItem* pMenuItem = m_pGUIThemePulldown->GetSelectedMenuItem();
	if (pMenuItem != NULL)
	{
		if (pMenuItem->GetLabel().GetText() == "None")
		{
			UnSkinGUI();
		}
		else
		{
			m_pFrontendManager->LoadCommonGraphics(pMenuItem->GetLabel().GetText().c_str());
			SkinGUI();
		}
	}
}

void VoxGame::_FaceMergeCheckboxChanged(void *apData)
{
	VoxGame* lpVoxGame = (VoxGame*)apData;
	lpVoxGame->FaceMergeCheckboxChanged();
}

void VoxGame::FaceMergeCheckboxChanged()
{
	bool faceMerging = m_pFaceMergingCheckbox->GetToggled();

	m_pPlayer->RebuildVoxelCharacter(faceMerging);
}

void VoxGame::_StepUpdatePressed(void *apData)
{
	VoxGame* lpVoxGame = (VoxGame*)apData;
	lpVoxGame->StepUpdatePressed();
}

void VoxGame::StepUpdatePressed()
{
	m_pChunkManager->StepNextUpdate();
}

void VoxGame::_ConsoleReturnPressed(void *apData)
{
	VoxGame* lpVoxGame = (VoxGame*)apData;
	lpVoxGame->ConsoleReturnPressed();
}

void VoxGame::ConsoleReturnPressed()
{
	if (m_pConsoleTextbox->GetText() == "")
	{
		return;
	}

	char lChatString[8192];
	snprintf(lChatString, 8192, "%s", m_pConsoleTextbox->GetText().c_str());
	string chatMessage = lChatString;

	AddConsoleLabel(chatMessage);

	m_pConsoleTextbox->SetText("");
}
