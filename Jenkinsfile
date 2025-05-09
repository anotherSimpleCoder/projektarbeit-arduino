pipeline {
    agent {
        docker {
            image 'rocker/r-rmd'
            args '-u root' 
        }
    }

    stages {
        stage('Build PDF') {
            steps {
                sh 'Rscript render.R'
                archiveArtifacts artifacts: '*.pdf', fingerprint: true
            }
        }
    }
}