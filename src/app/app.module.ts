import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { HttpClientModule } from '@angular/common/http';
import { FormsModule} from '@angular/forms';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { LoginComponent } from './components/login/login.component';
import { ScriptComponent } from './components/script/script.component';

import { AuthService } from './services/auth.service';
import { TokenInterceptorService } from './services/token-interceptor.service';

import {  } from './components/login/login.component.spec';
import { HTTP_INTERCEPTORS } from '@angular/common/http';
import { importExpr } from '@angular/compiler/src/output/output_ast';
import { from } from 'rxjs';
import { AuthGuard } from './services/auth.guard';
import { DecodeComponent } from './components/decode/decode.component';

@NgModule({
  declarations: [
    AppComponent,
    LoginComponent,
    ScriptComponent,
    DecodeComponent,
  ],
  imports: [
    BrowserModule,
    HttpClientModule,
    AppRoutingModule,
    FormsModule
  ],
  exports: [
  ],
  providers: [AuthService, AuthGuard, 
    {
      provide: HTTP_INTERCEPTORS,
      useClass: TokenInterceptorService,
      multi: true
    }
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
